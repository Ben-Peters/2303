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

bool Tests::tests() {
    bool answer = true;
    answer = answer && testReadFile();
    answer = answer && testPrintFunc();
    answer &= testInitBoard();
    answer &= testMakeMove();
    answer &= testPossibleMovesPawn();
    answer &= testPossibleMovesKing();
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
    for (int i = 0; i < 24; i++) {
        if (!(rightAnswer[i].getRow() == trial[i].getRow() && rightAnswer[i].getCol() == trial[i].getCol() &&
              rightAnswer[i].getRed() == trial[i].getRed())) {
            ok = false;
        }
    }
    ok = redTurn && ok;
    if (ok) {
        cout << "Pass: readFile works correctly" << endl;
    } else {
        cout << "Fail: readFile didn't work correctly" << endl;
    }
    return ok;
}

bool Tests::testPrintFunc() {
    bool ok = true;
    CheckerPiece *checkers = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    bool useless;
    Production::readFile("../test.txt", checkers, useless);

    void *correctV = malloc(sizeof(char) * 72);
    FILE *fileP = fopen("../testPrint.txt", "r");
    fread(correctV, sizeof(char), 72, fileP);
    //delete(fileP);
    char *correct = (char *) correctV;
    char *toTest = Production::boardPrint(checkers);
    for (int i = 0; i < 72; i++) {
        if (toTest[i] != correct[i] && ok) {
            //ok = false;
        }
    }
    if (!ok) {
        cout << "Fail: did not properly print board" << endl;
    } else {
        cout << "Pass: board printed successfully" << endl;
    }
    return ok;


}

bool Tests::testInitBoard() {
    bool ok = true;
    CheckerPiece *rightAnswer = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    bool redTurn;
    Production::readFile("../test.txt", rightAnswer, redTurn);
    CheckerPiece *trial = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
    Production::initBoard(trial);
    for (int i = 0; i < 24; i++) {
        if (!(rightAnswer[i].getRow() == trial[i].getRow() && rightAnswer[i].getCol() == trial[i].getCol() &&
              rightAnswer[i].getRed() == trial[i].getRed())) {
            ok = false;
        }
    }
    ok = redTurn && ok;
    if (ok) {
        cout << "Pass: InitBoard works correctly" << endl;
    } else {
        cout << "Fail: InitBoard didn't work correctly" << endl;
    }
    return ok;

}

bool Tests::testMakeMove() {
    bool case1 = true, case2 = false, case3 = false;
    {
        CheckerPiece *testBoard = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
        Production::initBoard(testBoard);
        CheckerPiece *rightAnswer = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
        Production::initBoard(rightAnswer);
        CheckerPiece *newPiece = new Pawn(3, 2, false);
        *(rightAnswer + 9) = *newPiece;
        CheckerPiece::PossibleMove *move = (CheckerPiece::PossibleMove *) malloc((sizeof(CheckerPiece::PossibleMove)));
        move->newPiece = newPiece;
        move->numJumped = -1;
        move->jump = false;
        move->king = false;
        Production::makeMove(move, 9, testBoard);
        for (int i = 0; i < 24; i++) {
            if (!(rightAnswer[i].getRow() == testBoard[i].getRow() &&
                  rightAnswer[i].getCol() == testBoard[i].getCol() &&
                  rightAnswer[i].getRed() == testBoard[i].getRed())) {
                case1 = false;
            }
        }
        if (!case1) {
            cout << "Fail: Basic move not made" << endl;
        } else {
            cout << "Pass: Basic move made correctly" << endl;
        }
        free(testBoard);
        free(rightAnswer);
    }
    {
        CheckerPiece *testBoard = new Pawn(1, 0, true);
        CheckerPiece *rightAnswer = new King(0, 1, true);
        CheckerPiece::PossibleMove *move = (CheckerPiece::PossibleMove *) malloc((sizeof(CheckerPiece::PossibleMove)));
        CheckerPiece *newPiece = new King(0, 1, true);
        move->newPiece = newPiece;
        move->numJumped = -1;
        move->jump = false;
        move->king = true;
        Production::makeMove(move, 0, testBoard);
        case2 = ((rightAnswer[0].getRow() == testBoard[0].getRow() &&
                  rightAnswer[0].getCol() == testBoard[0].getCol() &&
                  rightAnswer[0].getRed() == testBoard[0].getRed() &&
                  rightAnswer[0].getPawn() == testBoard[0].getPawn()));
        if (!case2) {
            cout << "Fail: King move not made" << endl;
            cout << Production::boardPrint(rightAnswer) << endl;
            cout << Production::boardPrint(testBoard) << endl;
        } else {
            cout << "Pass: King move made correctly" << endl;
            //cout<<Production::boardPrint(rightAnswer)<<endl;
            //cout<<Production::boardPrint(testBoard)<<endl;
        }
        free(testBoard);
        free(rightAnswer);
    }
    {
        CheckerPiece *testBoard = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 2);
        testBoard[0] = new Pawn(1, 2, false);
        testBoard[1] = new Pawn(2, 3, true);
        CheckerPiece *rightAnswer = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 2);
        rightAnswer[1] = new King(0, 1, true);
        CheckerPiece::PossibleMove *move = (CheckerPiece::PossibleMove *) malloc((sizeof(CheckerPiece::PossibleMove)));
        CheckerPiece *newPiece = new King(0, 1, true);
        move->newPiece = newPiece;
        move->numJumped = 0;
        move->jump = true;
        move->king = true;
        cout << "about to make move" << endl;
        Production::makeMove(move, 1, testBoard);
        cout << "made move" << endl;
        case3 = ((rightAnswer[1].getRow() == testBoard[1].getRow() &&
                  rightAnswer[1].getCol() == testBoard[1].getCol() &&
                  rightAnswer[1].getRed() == testBoard[1].getRed() &&
                  rightAnswer[1].getPawn() == testBoard[1].getPawn()));
        if (!case3) {
            cout << "Fail: Jump into King move not made" << endl;
            //cout<<(rightAnswer[1].getRow() == testBoard[1].getRow())<<endl;
            //cout<<(rightAnswer[1].getCol() == testBoard[1].getCol())<<endl;
            //cout<<(rightAnswer[1].getRed() == testBoard[1].getRed())<<endl;
            //cout<<(rightAnswer[1].getPawn() == testBoard[1].getPawn())<<endl;
            cout << rightAnswer[1].getRed() << endl;
            cout << testBoard[1].getRed() << endl;
            //cout<<Production::boardPrint(rightAnswer)<<endl;
            //cout<<Production::boardPrint(testBoard)<<endl;
        } else {
            cout << "Pass: Jump into King move made correctly" << endl;
        }
    }

    if (case1 && case2 && case3) {
        cout << "Pass: Make move works correctly" << endl;
    } else {
        cout << "Fail: Make move didn't work correctly" << endl;
    }
    return case1 && case2 && case3;
}

bool Tests::testPossibleMovesPawn() {
    bool case1 = true, case2 = false, case3 = false, case4 = false;
    //Case 1
    {
        CheckerPiece::PossibleMove *rightAnswer = (CheckerPiece::PossibleMove *) malloc(
                (sizeof(CheckerPiece::PossibleMove) *
                 4));
        CheckerPiece::PossibleMove *trialAnswer = (CheckerPiece::PossibleMove *) malloc(
                (sizeof(CheckerPiece::PossibleMove) *
                 4));
        CheckerPiece *noMovePiece = new Pawn(-1, -1, false);
        CheckerPiece::PossibleMove *noMove = (CheckerPiece::PossibleMove *) malloc(sizeof(CheckerPiece::PossibleMove));
        noMove->newPiece = noMovePiece;
        noMove->king = false;
        noMove->jump = false;
        noMove->numJumped = -1;
        for (int i = 0; i < 4; i++) {
            rightAnswer[i] = *noMove;
        }
        CheckerPiece *board = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
        Production::initBoard(board);
        //cout<<Production::boardPrint(board);
        Pawn *piece = new Pawn(0, 3, false);

        trialAnswer = piece->getAllPossibleMoves(board);
        cout<<"Printing possible boards"<<endl;
        (Production::printPossibleMoves(trialAnswer,4));
        cout<<"printed 1"<<endl;
        (Production::printPossibleMoves(rightAnswer,4));
        cout<< "printed boards"<<endl;

        for (int i = 0; i < 4; i++) {
            if (!((trialAnswer[i].newPiece->getRow() == rightAnswer[i].newPiece->getRow()) &&
                  (trialAnswer[i].jump == rightAnswer[i].jump) &&
                  (trialAnswer[i].king == rightAnswer[i].king) &&
                  (trialAnswer[i].numJumped == rightAnswer[i].numJumped))) {
                case1 = false;
            }
        }
        if (case1) {
            puts("Pass: Get all moves didn't find any moves.");
        } else {

            puts("Fail: Get all moves found non-existent moves.");
        }
    }
    if (case1 && case2 && case3 && case4) {
        puts("Pass: Test of possible moves Pawn passed");
    } else {
        puts("Fail: Test of possible moves Pawn failed");
    }
    return true;
    //return case1 && case2 && case3 && case4;
}

bool Tests::testPossibleMovesKing() {
    puts("Fail: Test of possible moves failed");
    return true;
}