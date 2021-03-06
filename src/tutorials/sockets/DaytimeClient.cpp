/*
 * DaytimeClient.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: gdeforest
 */

#include "include/DaytimeClient.h"

DaytimeClient::DaytimeClient()
{
	id = -1;
	resolver = new tcp::resolver(ioService);
}

DaytimeClient::DaytimeClient(int id)
{
	this->id = id;
	resolver = new tcp::resolver(ioService);
}

void DaytimeClient::Execute(const std::string& endpoint)
{
	try
	{
		tcp::resolver::query query(endpoint, "daytime");
		tcp::resolver::iterator endpoint_iterator = resolver->resolve(query);

		tcp::socket socket(ioService);
		boost::asio::connect(socket, endpoint_iterator);

		for (;;)
		{
			boost::array<char, 128> buf;
			boost::system::error_code error;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			if (error == boost::asio::error::eof) {
				break; // Connection closed cleanly by peer.
			} else if (error) {
				throw boost::system::system_error(error); // Some other error.
			}

			std::cout << "Client " << id << ":  ";
			std::cout.write(buf.data(), len);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
