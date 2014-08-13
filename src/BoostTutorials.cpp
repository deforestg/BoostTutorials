//============================================================================
// Name        : BoostTutorials.cpp
// Author      : Gabriel de Forest
// Version     : 1
// Copyright   : No copyright
// Description : Boost tutorials in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "tutorials/include/TutorialOne.h"
#include "tutorials/include/TutorialTwo.h"
#include "tutorials/include/TutorialThree.h"
#include "tutorials/include/TutorialFour.h"
#include "tutorials/include/TutorialFive.h"

using namespace std;

int main() {
	TutorialOne *T1 = new TutorialOne();
	T1->Execute();

	TutorialTwo *T2 = new TutorialTwo();
	T2->Execute();

	TutorialThree *T3 = new TutorialThree(2, 1);
	T3->Execute();

	TutorialFour *T4 = new TutorialFour(3, 1);
	T4->Execute();

	TutorialFive *T5 = new TutorialFive(20, 2, 4);
	T5->Execute();

	return 0;
}
