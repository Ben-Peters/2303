/*
 * Production.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#define BOARD_SIZE 8

#include "CheckerPiece.h"
#include "Pawn.h"
#include "King.h"
class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
    int promptNumOfMoves();
};

#endif /* PRODUCTION_H_ */
