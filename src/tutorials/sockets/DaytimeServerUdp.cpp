/*
 * DaytimeServerUdp.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: gdeforest
 */

#include "include/DaytimeServerUdp.h"

DaytimeServerUdp::DaytimeServerUdp()
{
	acceptor = new tcp::acceptor(ioService, tcp::endpoint(tcp::v4(), 13));
}

std::string DaytimeServerUdp::makeDaytimeString()
{
	time_t now = time(0);
	return ctime(&now);
}

void DaytimeServerUdp::Start()
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
