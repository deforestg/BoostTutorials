/*
 * TutorialThree.h
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#ifndef TUTORIALTHREE_H_
#define TUTORIALTHREE_H_

class TutorialThree
{
	private:
		boost::asio::deadline_timer* t;
		boost::asio::io_service io;
		int count;
		int countTo;
		int interval;
		void bindWait();
		void print(
			const boost::system::error_code& /*e*/
		);
	public:
		TutorialThree(int countTo, int interval);
		void Execute();
};

#endif /* TUTORIALTHREE_H_ */
