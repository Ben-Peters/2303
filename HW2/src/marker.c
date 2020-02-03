/*
 * marker.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#include <stdlib.h>
#include <stdio.h>
#include "marker.h"

Marker* placeMarker(int r, int c)
{
	Marker* mP = (Marker*) malloc (sizeof(Marker));
	mP->index = 0;
	mP->row = r;
	mP->col = c;

	return mP;
}

Marker* makeAdjacentMarker(Marker* marker, int index){
    int dir = rand() % 8;
    int row = marker->row;
    int col = marker->col;
    switch (dir){
        case 0:
            row -= 1;
            break;

        case 1:
            row -= 1;
            col += 1;
            break;

        case 2:
            col += 1;
            break;

        case 3:
            row += 1;
            col += 1;
            break;

        case 4:
            row += 1;
            break;

        case 5:
            row += 1;
            col -= 1;
            break;

        case 6:
            col -= 1;
            break;

        case 7:
            row -= 1;
            col -= 1;
            break;

        default:
            puts("Whoops. Ya done goofed. Marker.c -> makeAdjacentMarker");
    }
    if (row == -1){
        row = 19;
    }else if (row == 20){
        row = 0;
    }
    if (col == -1){
        col = 19;
    }else if (col == 20){
        col = 0;
    }
    marker = placeMarker(row, col);
    marker->index = index;
    return marker;
}
