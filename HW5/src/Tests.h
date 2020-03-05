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
};

#endif /* TESTS_H_ */
