/*
 * DaytimeServerTcp.h
 *
 *  Created on: Aug 13, 2014
 *      Author: gdeforest
 */

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

#ifndef DAYTIMESERVERTCP_H_
#define DAYTIMESERVERTCP_H_

class DaytimeServerTcp
{
	private:
		boost::asio::io_service ioService;
		tcp::acceptor* acceptor;
		std::string makeDaytimeString();
	public:
		DaytimeServerTcp();
		void Start();
};


#endif /* DAYTIMESERVERTCP_H_ */
