/*
 * AdjMat.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#include "AdjMat.h"
#include <stdio.h>

void init(AdjMat* adjMP)
{
	int ncols = adjMP->n;
	printf("In init with ncols = %d\n", ncols);
	for(int row = 0; row<ncols; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			*((adjMP->edgesP)+(row*ncols)+col)= 0;
		}
	}

}

void setEdge(AdjMat* adjMP, int row, int col)
{

	int ncols = adjMP->n;
	int* arrayBeginning = adjMP->edgesP;
	printf("%d", (ncols*row) +col);
	*(arrayBeginning + (ncols*row) +col) = 1;
	*(arrayBeginning + (ncols*col) + row) = 1;
}
int getEdge(AdjMat* adjMP, int row, int col)
{
	int ncols = adjMP->n;
	int* arrayBeginning = adjMP->edgesP;
	return *(arrayBeginning + (ncols*row) +col) ;
}

