/*
 * DaytimeServer.h
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

#ifndef DAYTIMESERVER_H_
#define DAYTIMESERVER_H_

class DaytimeServer
{
	private:
		boost::asio::io_service ioService;
		tcp::acceptor* acceptor;
		std::string makeDaytimeString();
	public:
		DaytimeServer();
		void Start();
};


#endif /* DAYTIMESERVER_H_ */
