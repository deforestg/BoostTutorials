/*
 * DaytimeClient.h
 *
 *  Created on: Aug 14, 2014
 *      Author: gdeforest
 */

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using boost::asio::ip::udp;

#ifndef DAYTIMECLIENTUDP_H_
#define DAYTIMECLIENTUDP_H_

class DaytimeClientUdp
{
	private:
		boost::asio::io_service ioService;
		udp::resolver *resolver;
		int id;
	public:
		DaytimeClientUdp();
		DaytimeClientUdp(int id);
		void Execute(const std::string& endpoint);
};


#endif /* DAYTIMECLIENTUDP_H_ */
