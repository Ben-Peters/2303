/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include <stdlib.h>
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

void updateSpace(int* space, int numOfRows, int row, int col, int value){
    for (int i = 0; i < numOfRows; i++){
        for (int j = 0; j < numOfRows; j++){
            if (i == row && j == col){
                *(space+row*numOfRows+col) = value;
            }
        }
    }
}

int* getRandCoordinates(){
    int* coordinates = (int*) malloc(sizeof(int)*2);
    *(coordinates) = rand() % 20;
    *(coordinates+1) = rand() % 20;
    return coordinates;
}
