/*
 * marker.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#ifndef MARKER_H_
#define MARKER_H_

typedef struct
{
   int index;
   int row;
   int col;
}Marker;

#include <stdbool.h>

Marker* placeMarker(int, int);

#endif /* MARKER_H_ */
