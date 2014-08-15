/*
 * DaytimeServerUdp.h
 *
 *  Created on: Aug 14, 2014
 *      Author: gdeforest
 */

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

#ifndef DAYTIMESERVERUDP_H_
#define DAYTIMESERVERUDP_H_

class DaytimeServerUdp
{
	private:
		boost::asio::io_service ioService;
		tcp::acceptor* acceptor;
		std::string makeDaytimeString();
	public:
		DaytimeServerUdp();
		void Start();
};


#endif /* DAYTIMESERVERUDP_H_ */
