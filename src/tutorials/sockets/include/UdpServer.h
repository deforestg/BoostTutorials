/*
 * UdpServer.h
 *
 *  Created on: Aug 15, 2014
 *      Author: gdeforest
 */

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::udp;

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

class UdpServer
{
	public:
	UdpServer(boost::asio::io_service& ioService);
	private:
		udp::socket* socket;
		udp::endpoint endpoint;
		boost::array<char, 1> buffer;
		void startReceive();
		void handleReceive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/);
		void handleSend(
			boost::shared_ptr<std::string> /*message*/,
			const boost::system::error_code& /*error*/,
			std::size_t /*bytes_transferred*/
		);
		std::string makeDaytimeString();
};


#endif /* UDPSERVER_H_ */
