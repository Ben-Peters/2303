/*
 * marker.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#include <stdlib.h>
#include "marker.h"

Marker* placeMarker(int r, int c)
{
	Marker* mP = (Marker*) malloc (sizeof(Marker));
	mP->index = 0;
	mP->row = r;
	mP->col = c;

	return mP;
}
