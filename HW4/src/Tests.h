/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Production.h"
#include "AdjMat.h"
#include<stdio.h>
using namespace std;
class Tests {
public:
	Tests();
	virtual ~Tests();
    bool tests();
    bool testReadFile();
    bool testGotAdjacencyMatrix();
    bool testMakeLList();
    bool testEnqueue();
    bool testRemoveFromList();
    bool testPrintHistory();

};

#endif /* TESTS_H_ */
