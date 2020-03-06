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
#include <iostream>
using namespace std;
Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;
	answer = answer && testReadFile();
	answer = answer && testPrintFunc();
	return answer;
}

bool Tests::testReadFile() {
    bool ok = true;
    CheckerPiece *rightAnswer = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    Production::initBoard(rightAnswer);
    //Production::simplePrint(rightAnswer);
    CheckerPiece *trial = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    bool redTurn;
    Production::readFile("../test.txt", trial, redTurn);
    //Production::simplePrint(trial);
    for(int i = 0; i < 24; i++){
        if(!(rightAnswer[i].getRow() == trial[i].getRow() && rightAnswer[i].getCol() == trial[i].getCol() && rightAnswer[i].getRed() == trial[i].getRed())){
            ok = false;
        }
    }
        ok = redTurn && ok;
    if(ok){
        cout<<"Pass: readFile works correctly"<<endl;
    }else{
        cout << "Fail: readFile didn't work correctly"<<endl;
    }
    return ok;
}

bool Tests::testPrintFunc() {
	bool ok = true;
	CheckerPiece* checkers = (CheckerPiece*) malloc(sizeof(CheckerPiece) * 24);
	bool useless;
	Production::readFile("../test.txt", checkers, useless);

	void* correctV = malloc(sizeof(char) * 72);
	FILE* fileP = fopen("../testPrint.txt", "r");
	fread(correctV, sizeof(char), 72, fileP);
	delete(fileP);
	char* correct = (char*)correctV;
	char* toTest = Production::boardPrint(checkers);
	for(int i = 0; i < 72; i++){
		if(toTest[i] != correct[i] && ok){
			ok = false;
		}
	}
	if (!ok) {
		cout << "Fail: did not properly print board" << endl;
	}
	else {
		cout << "Pass: board printed successfully" << endl;
	}
	return ok;



}
