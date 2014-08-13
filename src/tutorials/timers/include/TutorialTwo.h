/*
 * TutorialTwo.h
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#ifndef TUTORIALTWO_H_
#define TUTORIALTWO_H_

class TutorialTwo
{
	private:
		boost::asio::deadline_timer* t;
		boost::asio::io_service io;
		void print(const boost::system::error_code& /*e*/);
	public:
		TutorialTwo();
		void Execute();
};


#endif /* TUTORIALTWO_H_ */
