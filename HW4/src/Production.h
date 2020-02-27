/*
 * Production.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#define FILENAMELENGTHALLOWANCE 50
#include<iostream>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
using namespace std;
#include "AdjMat.h"
#include "Room.h"
#include "LinkedList.h"
class Production {
public:
	Production();
	virtual ~Production();
    static bool prod(int argc, char* argv[]);
    static bool readFile(char* filename, int* nrooms, AdjMatrix::AdjMat* adjMP, Room** theRoomPs);
    //static void displayBoard();
    static int promptNumOfRooms();
    static float promptAmountTreasure();
};

#endif /* PRODUCTION_H_ */
