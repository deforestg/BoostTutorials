/*
 * TutorialFour.h
 *
 *  Created on: Aug 12, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#ifndef TUTORIALFOUR_H_
#define TUTORIALFOUR_H_

class TutorialFour
{
	private:
		boost::asio::deadline_timer* t;
		boost::asio::io_service io;
		int count;
		int countTo;
		int interval;
		void bindWait();
		void print();
	public:
		TutorialFour(int countTo, int interval);
		void Execute();
};

#endif /* TUTORIALFOUR_H_ */
