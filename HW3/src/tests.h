/*
 * tests.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_


#include "production.h"
#include "AdjMat.h"
bool tests();

bool testReadFile();
bool testGotAdjacencyMatrix();
bool testMakeLList();
bool testEnqueue();
bool testRemoveFromList();
bool testPrintHistory();


#endif /* TESTS_H_ */
