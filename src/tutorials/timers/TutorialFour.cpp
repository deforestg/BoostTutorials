/*
 * TutorialFour.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: gdeforest
 */

#include "include/TutorialFour.h"

TutorialFour::TutorialFour(int countTo, int interval)
{
	this->countTo = countTo;
	this->interval = interval;
	count = 0;
	t = new boost::asio::deadline_timer(io, boost::posix_time::seconds(this->interval));
}

void TutorialFour::bindWait()
{
	t->expires_at(t->expires_at() + boost::posix_time::seconds(interval));

	t->async_wait(
		boost::bind(&TutorialFour::print, this)
	);
}

void TutorialFour::print()
{
	if (count < countTo)
	{
		std::cout << count++ << "\n";
		this->bindWait();
	}
}

void TutorialFour::Execute()
{
	this->bindWait();

	io.run();

	std::cout << "Final count is " << count << "\n";
}
