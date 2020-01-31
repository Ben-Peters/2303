/*
 * space.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#ifndef SPACE_H_
#define SPACE_H_

#include <stdbool.h>
#include <stdlib.h>
bool initSpace(int*, int);

/**
 * Updates the value at the specified coordinates within the space
 * @param space The space to update
 * @param numOfRows Number of rows in the space
 * @param row The row where the update should occur
 * @param col The column where the update should occur
 * @param value New value
 */
void updateSpace(int* space, int numOfRows, int row, int col, int value);

/**
 * Gets a random pair of coordinates
 * @return A pointer to a pair of coordinates
 */
int* getRandCoordinates();

#endif /* SPACE_H_ */
