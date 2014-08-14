/*
 * DaytimeClient.h
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

#ifndef DAYTIMECLIENT_H_
#define DAYTIMECLIENT_H_

class DaytimeClient
{
	private:
		boost::asio::io_service ioService;
		tcp::resolver *resolver;
	public:
		DaytimeClient();
		void Execute(const std::string& endpoint);
};


#endif /* DAYTIMECLIENT_H_ */
