/*
 * DaytimeClientUdp.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: gdeforest
 */

#include "include/DaytimeClientUdp.h"

DaytimeClientUdp::DaytimeClientUdp()
{
	id = -1;
	resolver = new udp::resolver(ioService);
}

DaytimeClientUdp::DaytimeClientUdp(int id)
{
	this->id = id;
	resolver = new udp::resolver(ioService);
}

void DaytimeClientUdp::Execute(const std::string& endpoint)
{
	try
	{
		udp::resolver::query query(udp::v4(), endpoint, "daytime");
		udp::endpoint receiver_endpoint = *resolver->resolve(query);

		udp::socket socket(ioService);
		socket.open(udp::v4());

		for (;;)
		{
			boost::array<char, 1> send_buf  = {{ 0 }};
			socket.send_to(boost::asio::buffer(send_buf), receiver_endpoint);

			boost::array<char, 128> recv_buf;
			udp::endpoint sender_endpoint;

			size_t len = socket.receive_from(
				boost::asio::buffer(recv_buf),
				sender_endpoint
			);

			std::cout << "Client " << id << ":  ";
			std::cout.write(recv_buf.data(), len);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
