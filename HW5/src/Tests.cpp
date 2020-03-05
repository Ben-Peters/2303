/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include <cstring>
#include <cstdlib>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;
	bool ok1= false;
	ok1 = testReadFile();
	return answer;
}

bool Tests::testReadFile() {
    bool ok = true;
    CheckerPiece *rightAnswer = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            *(rightAnswer + (i * 4) + j) = new Pawn(i, (2 * j) + ((i + 1) % 2), false);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            *(rightAnswer + (i * 4) + j) = new Pawn(i + 5, (2 * j) + (i % 2), true);
        }
    }
    CheckerPiece *trial = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    bool redTurn;
    Production::readFile("../test.txt", trial, redTurn);
    for(int i = 0; i < 24; i++){
        if(!(rightAnswer[i].getRow() == trial[i].getRow() && rightAnswer[i].getCol() == trial[i].getCol() && rightAnswer[i].getRed() == trial[i].getRed())){
            ok = false;
        }
    }
        ok = redTurn && ok;
    return ok;
}