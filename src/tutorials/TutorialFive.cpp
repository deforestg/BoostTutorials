/*
 * TutorialFive.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "include/TutorialFive.h"

TutorialFive::TutorialFive(int countTo, int interval, int numTimers)
{
	this->countTo = countTo;
	this->interval = interval;
	count = 0;
	strand = new boost::asio::strand(io);

	for (int i = 0; i < numTimers; i++) {
		timers.push_back(new boost::asio::deadline_timer(io));
	}
}

void TutorialFive::bindWait()
{
	for (std::vector<boost::asio::deadline_timer*>::iterator it = timers.begin() ; it != timers.end(); ++it) {
		(*it)->expires_from_now(boost::posix_time::seconds(interval));

		(*it)->async_wait(
			strand->wrap(
				boost::bind(&TutorialFive::print, this, it - timers.begin())
			)
		);
	}
}

void TutorialFive::print(int timerNum)
{
	if (count < countTo)
	{
		std::cout << "Timer " << timerNum << ", Count: " << count++ << "\n";
		this->bindWait();
	}
}

void TutorialFive::Execute()
{
	this->bindWait();
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
	io.run();
	t.join();

	std::cout << "Final count is " << count << "\n";
}
