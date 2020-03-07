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
#include <fstream>
class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
    int promptNumOfMoves();
    static void initBoard(CheckerPiece*&);
	static bool readFile(char* filename, CheckerPiece *&pieces, bool &redTurn);
    static void makeMove(CheckerPiece::PossibleMove*, int, CheckerPiece *&);
    static void simplePrint(CheckerPiece*);
    static char* boardPrint(CheckerPiece*);
    static void doWriteFile(char*, std::ofstream*);
};

#endif /* PRODUCTION_H_ */
