/*
 * DaytimeServerUdp.cpp
 *
 *  Created on: Aug 15, 2014
 *      Author: gdeforest
 */

#include "include/DaytimeServerUdp.h"

DaytimeServerUdp::DaytimeServerUdp()
{
	socket = new udp::socket(ioService, udp::endpoint(udp::v4(), 13));
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
			boost::array<char, 1> recv_buf;
			udp::endpoint remote_endpoint;
			boost::system::error_code error;
			socket->receive_from(
				boost::asio::buffer(recv_buf),
				remote_endpoint,
				0,
				error
			);

			if (error && error != boost::asio::error::message_size) {
				throw boost::system::system_error(error);
			}

			std::string message = makeDaytimeString();

			boost::system::error_code ignored_error;
			socket->send_to(
				boost::asio::buffer(message),
				remote_endpoint,
				0,
				ignored_error
			);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
