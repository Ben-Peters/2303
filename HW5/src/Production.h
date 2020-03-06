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
class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
    int promptNumOfMoves();
    static void initBoard(CheckerPiece*&);
	static bool readFile(char* filename, CheckerPiece *&pieces, bool &redTurn);
    static void makeMove(CheckerPiece::PossibleMove*);
    static void simplePrint(CheckerPiece*);
    static char* boardPrint(CheckerPiece*);
};

#endif /* PRODUCTION_H_ */
