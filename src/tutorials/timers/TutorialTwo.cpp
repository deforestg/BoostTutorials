/*
 * TutorialTwo.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

#include "include/TutorialTwo.h"

TutorialTwo::TutorialTwo()
{
	t = new boost::asio::deadline_timer(io, boost::posix_time::seconds(1));
}

void TutorialTwo::print(const boost::system::error_code& /*e*/)
{
	std::cout << "Tutorial Two!\n";
}

void TutorialTwo::Execute()
{
	t->async_wait(boost::bind(&TutorialTwo::print, this, _1));
	io.run();
}
