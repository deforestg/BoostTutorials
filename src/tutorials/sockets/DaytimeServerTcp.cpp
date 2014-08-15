/*
 * DaytimeServerTcp.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: gdeforest
 */

#include "include/DaytimeServerTcp.h"

DaytimeServerTcp::DaytimeServerTcp()
{
	acceptor = new tcp::acceptor(ioService, tcp::endpoint(tcp::v4(), 13));
}

std::string DaytimeServerTcp::makeDaytimeString()
{
	time_t now = time(0);
	return ctime(&now);
}

void DaytimeServerTcp::Start()
{
	try
	{
		for (;;) {
			tcp::socket socket(ioService);
			acceptor->accept(socket);

			std::string message = makeDaytimeString();

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
