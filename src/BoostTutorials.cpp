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
#include "tutorials/sockets/include/DaytimeServer.h"

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

void runTheDaytimes()
{
    pid_t pid = fork();

    if (pid == 0) {
    	DaytimeServer *server = new DaytimeServer();
    	server->Start();
    } else {
    	DaytimeClient *client = new DaytimeClient();
    	client->Execute((const std::string&)"127.0.1.1");
    }
}

int main()
{
//	runTheTimers();

	runTheDaytimes();

	return 0;
}
