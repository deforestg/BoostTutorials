/*
 * TutorialTwo.h
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

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
