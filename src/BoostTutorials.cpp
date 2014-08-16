//============================================================================
// Name        : BoostTutorials.cpp
// Author      : Gabriel de Forest
// Version     : 1
// Copyright   : No copyright
// Description : Boost tutorials in C++, Ansi-style
//============================================================================

#include "tutorials/timers/include/TutorialOne.h"
#include "tutorials/timers/include/TutorialTwo.h"
#include "tutorials/timers/include/TutorialThree.h"
#include "tutorials/timers/include/TutorialFour.h"
#include "tutorials/timers/include/TutorialFive.h"

#include "tutorials/sockets/include/DaytimeClient.h"
#include "tutorials/sockets/include/DaytimeClientUdp.h"
#include "tutorials/sockets/include/DaytimeServerTcp.h"
#include "tutorials/sockets/include/DaytimeServerUdp.h"
#include "tutorials/sockets/include/TcpServer.h"
#include "tutorials/sockets/include/UdpServer.h"

void runTheTimers()
{
	TutorialOne *T1 = new TutorialOne();
	T1->Execute();

	TutorialTwo *T2 = new TutorialTwo();
	T2->Execute();

	TutorialThree *T3 = new TutorialThree(2, 1);
	T3->Execute();

	TutorialFour *T4 = new TutorialFour(2, 1);
	T4->Execute();

	TutorialFive *T5 = new TutorialFive(20, 2, 4);
	T5->Execute();
}

void runDaytimeTcp()
{
    pid_t pid = fork();

    if (pid == 0) {
    	DaytimeServerTcp *server = new DaytimeServerTcp();
    	server->Start();
    } else {
    	DaytimeClient *client = new DaytimeClient();
    	client->Execute((const std::string&)"127.0.1.1");
    }
}

void runDaytimeTcpAsync()
{
    pid_t pid = fork();

    if (pid == 0) {
		try
		{
			boost::asio::io_service ioService;
			TcpServer server(ioService);
			ioService.run();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
    } else {
        pid_t pid = fork();

        if (pid == 0) {
        	DaytimeClient *client = new DaytimeClient(1);
        	for (;;) {
            	client->Execute((const std::string&)"127.0.1.1");
        	}
        } else {
        	DaytimeClient *client = new DaytimeClient(2);
        	for (;;) {
            	client->Execute((const std::string&)"127.0.1.1");
        	}
        }
    }
}

void runDaytimeUdp()
{
    pid_t pid = fork();

    if (pid == 0) {
    	DaytimeServerUdp *server = new DaytimeServerUdp();
    	server->Start();
    } else {
    	DaytimeClientUdp *client = new DaytimeClientUdp();
    	client->Execute((const std::string&)"127.0.1.1");
    }
}

void runDaytimeUdpAsync()
{
    pid_t pid = fork();

    if (pid == 0) {
		try
		{
		    boost::asio::io_service ioService;
		    UdpServer server(ioService);
		    ioService.run();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
    } else {
        pid_t pid = fork();

        if (pid == 0) {
        	DaytimeClientUdp *client = new DaytimeClientUdp(1);
        	for (;;) {
            	client->Execute((const std::string&)"127.0.1.1");
        	}
        } else {
        	DaytimeClientUdp *client = new DaytimeClientUdp(2);
        	for (;;) {
            	client->Execute((const std::string&)"127.0.1.1");
        	}
        }
    }
}

void runDaytimeBothAsync()
{
    pid_t pid = fork();

    if (pid == 0) {
		try
		{
		    boost::asio::io_service ioService;
		    TcpServer server1(ioService);
		    UdpServer server(ioService);
		    ioService.run();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
    } else {
        pid_t pid = fork();

        if (pid == 0) {
        	DaytimeClientUdp *client = new DaytimeClientUdp(1);
        	for (;;) {
            	client->Execute((const std::string&)"127.0.1.1");
        	}
        } else {
        	DaytimeClient *client = new DaytimeClient(2);
        	for (;;) {
            	client->Execute((const std::string&)"127.0.1.1");
        	}
        }
    }
}

int main()
{
//	runTheTimers();
//	runDaytimeTcp()
//	runDaytimeTcpAsync();
//	runDaytimeUdp();
//	runDaytimeUdpAsync();

	runDaytimeBothAsync();

	return 0;
}
