/*
 * TutorialOne.h
 *
 *  Created on: Aug 11, 2014
 *      Author: gdeforest
 */

#ifndef TUTORIALONE_H_
#define TUTORIALONE_H_

class TutorialOne
{
	private:
		boost::asio::deadline_timer* t;
		boost::asio::io_service io;
	public:
		TutorialOne();
		void Execute();
};


#endif /* TUTORIALONE_H_ */
