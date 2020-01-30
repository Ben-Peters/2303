/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "display.h"

bool production(int argc, char* argv[])
{

	//obtain space for 20x20 of integers
	int size = 20;
	int* theSpaceP = (int*) malloc(size*size*sizeof(int));
    bool okInit = initSpace(theSpaceP, size);
	print2DArray(theSpaceP, size);

	//we'll want to read the file
	return true;
}


