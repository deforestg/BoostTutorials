/*
 * TutorialFive.h
 *
 *  Created on: Aug 12, 2014
 *      Author: gdeforest
 */

#ifndef TUTORIALFIVE_H_
#define TUTORIALFIVE_H_

class TutorialFive
{
	private:
		std::vector<boost::asio::deadline_timer*> timers;
		boost::asio::io_service io;
		boost::asio::strand* strand;
		int count;
		int countTo;
		int interval;
		void bindWait();
		void print(int timerNum);
	public:
		TutorialFive(int countTo, int interval, int numTimers);
		void Execute();
};

#endif /* TUTORIALFIVE_H_ */
