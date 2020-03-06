/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Production.h"

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
    static bool testReadFile();
    static bool testPrintFunc();
    static bool testInitBoard();
    static bool testMakeMove();
    static bool testPossibleMovesPawn();
    static bool testPossibleMovesKing();
};

#endif /* TESTS_H_ */
