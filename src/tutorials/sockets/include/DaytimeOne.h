/*
 * DaytimeOne.h
 *
 *  Created on: Aug 12, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using boost::asio::ip::tcp;

#ifndef DAYTIMEONE_H_
#define DAYTIMEONE_H_

class DaytimeOne
{
	private:
		boost::asio::io_service ioService;
		tcp::resolver *resolver;
	public:
		DaytimeOne();
		void Execute();
};


#endif /* DAYTIMEONE_H_ */
