/*
 * AdjMat.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#ifndef ADJMAT_H_
#define ADJMAT_H_

#include <stdbool.h>
typedef struct
{
	int n;
	int* edgesP;
}AdjMat;


void setEdge(AdjMat* adjMP, int row, int col);
int getEdge(AdjMat* adjMP, int row, int col);
void init(AdjMat* adjMP);

#endif /* ADJMAT_H_ */
