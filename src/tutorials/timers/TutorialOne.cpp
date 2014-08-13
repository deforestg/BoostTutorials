/*
 * TutorialOne.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "include/TutorialOne.h"

TutorialOne::TutorialOne()
{
	t = new boost::asio::deadline_timer(io, boost::posix_time::seconds(1));
}

void TutorialOne::Execute()
{
	t->wait();
	std::cout << "Tutorial One!\n";
}
