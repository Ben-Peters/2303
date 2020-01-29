/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include "space.h"

bool initSpace(int* corner, int howManyRows)
{
	bool ok = true;
	for(int row = 0; row< howManyRows; row++)
	{
		for(int col = 0; col < howManyRows; col++)
		{
			*(corner+row*howManyRows + col) = 0;
		}
	}
	return ok;
}
