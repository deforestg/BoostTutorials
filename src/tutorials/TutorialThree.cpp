/*
 * TutorialThree.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "include/TutorialThree.h"

TutorialThree::TutorialThree(int countTo, int interval)
{
	this->countTo = countTo;
	this->interval = interval;
	count = 0;
	t = new boost::asio::deadline_timer(io, boost::posix_time::seconds(interval));
}

void TutorialThree::bindWait()
{
	t->expires_at(t->expires_at() + boost::posix_time::seconds(interval));

	t->async_wait(
		boost::bind(&TutorialThree::print, this, _1)
	);
}

void TutorialThree::print(const boost::system::error_code& /*e*/)
{
	if (count < countTo)
	{
		std::cout << count++ << "\n";
		this->bindWait();
	}
}

void TutorialThree::Execute()
{
	this->bindWait();

	io.run();

	std::cout << "Final count is " << count << "\n";
}
