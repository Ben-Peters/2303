//
// Created by Ben on 3/2/2020.
//

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "CheckerPiece.h"

CheckerPiece::CheckerPiece(int row, int col, bool red) {
    this->row = row;
    this->col = col;
    this->red = red;
}

CheckerPiece::~CheckerPiece() {}

int CheckerPiece::getRow() {
    return row;
}

int CheckerPiece::getCol() {
    return col;
}

bool CheckerPiece::getRed() {
    return red;
}

bool CheckerPiece::getPawn() {
    return pawn;
}

void CheckerPiece::setRow(int value) {
    row = value;
}

void CheckerPiece::setCol(int value) {
    col = value;
}

void CheckerPiece::setRed(bool value) {
    red = value;
}

CheckerPiece::CheckerPiece(Pawn *pPawn) {
    row = pPawn->getRow();
    col = pPawn->getCol();
    red = pPawn->getRed();
    pawn = true;
}

CheckerPiece::PossibleMove *CheckerPiece::getAllPossibleMoves(CheckerPiece *) {
    puts("nullptr");
    return nullptr;
}

CheckerPiece::CheckerPiece(King *pKing) {
    row = pKing->getRow();
    col = pKing->getCol();
    red = pKing->getRed();
    pawn = false;
}

CheckerPiece::CheckerPiece(CheckerPiece *pPiece) {
    row = pPiece->getRow();
    col = pPiece->getCol();
    red = pPiece->getRed();
    pawn = pPiece->getPawn();
}

King::King(int row, int col, bool red) : CheckerPiece(row, col, red) {
    this->row = row;
    this->col = col;
    this->red = red;
    this->pawn = false;
}

King::~King() {}

CheckerPiece::PossibleMove *King::getAllPossibleMoves(CheckerPiece *pieces) {
    puts("kingStart?");
    CheckerPiece::PossibleMove *possibleMoves = (CheckerPiece::PossibleMove *) malloc(sizeof(PossibleMove) * 4);
    int k = 0;
    CheckerPiece::PossibleMove *noMove = (PossibleMove * )(malloc(sizeof(PossibleMove)));
    *noMove->newPiece = new King(-1, -1, false);
    for (int l = 1; l >= -1; l += -2) {
        for (int i = -1; i <= 1; i += 2) {
            for (int j = 0; j < 24; j++) {
                if (this->row + 1 == (pieces + j)->getRow() && this->col + i == (pieces + j)->getCol() &&
                    this->red == (pieces + j)->getRed()) {
                    //same place same team
                    *(possibleMoves + k++) = *noMove;
                } else if (this->row + l != (pieces + j)->getRow() && this->col + i != (pieces + j)->getCol() &&
                           (this->row + l < 8 && this->col + i < 8 && this->col + i > -l)) {
                    //valid move with no jump or anything like that
                    CheckerPiece::PossibleMove *move = (PossibleMove * )(malloc(sizeof(PossibleMove)));
                    move->newPiece = new King(this->row + l, this->col + i, this->red);
                    move->jump = false;
                    move->numJumped = -1;
                    move->king = false;
                    *(possibleMoves + k++) = *move;
                    free(move);
                } else if (this->row + l == (pieces + j)->getRow() && this->col + i == (pieces + j)->getCol() &&
                           this->red != (pieces + j)->getRed()) {
                    //same space different team with +/-1(Possible jump)
                    if ((this->row == 6 && !(this->red)) || (this->row == 1 && (this->red))) {
                        //jump would be off the board
                        *(possibleMoves + k++) = *noMove;
                    } else if (((this->row == 5 && !(this->red)) || (this->row == 2 && (this->red))) &&
                               (this->col + (i * 2) <= 7 && this->col + (i * 2) >= 0)) {
                        //valid jump into king but that doesnt matter because its a king already
                        CheckerPiece::PossibleMove *move = (PossibleMove * )(malloc(sizeof(PossibleMove)));
                        move->newPiece = new King(this->row + (l * 2), this->col + (2 * i), this->red);
                        move->jump = true;
                        move->numJumped = j;
                        move->king = false;
                        *(possibleMoves + k++) = *move;
                        free(move);
                    } else {
                        //valid jump but not a king
                        CheckerPiece::PossibleMove *move = (PossibleMove * )(malloc(sizeof(PossibleMove)));
                        move->newPiece = new King(this->row + (l * 2), this->col + (2 * i), this->red);
                        move->jump = true;
                        move->numJumped = j;
                        move->king = false;
                        *(possibleMoves + k++) = *move;
                        free(move);
                    }
                } else {
                    *(possibleMoves + k++) = *noMove;
                }
            }
        }
    }
    free(noMove);
    return possibleMoves;
}

Pawn::Pawn(int row, int col, bool red) : CheckerPiece(row, col, red) {
    this->row = row;
    this->col = col;
    this->red = red;
}

Pawn::~Pawn() {}

CheckerPiece::PossibleMove *Pawn::getAllPossibleMoves(CheckerPiece *pieces) {
    puts("PawnMethodStart");
    CheckerPiece::PossibleMove *possibleMoves = (CheckerPiece::PossibleMove *) malloc(sizeof(PossibleMove) * 4);
    int k = 0;
    CheckerPiece::PossibleMove *noMove = (PossibleMove * )(malloc(sizeof(PossibleMove)));
    *noMove->newPiece = new Pawn(-1,-1,false);
    for (int x = 0; x < 4; x++) {
    	*(possibleMoves + x) = *noMove;
    }
    puts("a");
    for (int i = -1; i <= 1; i += 2) {
        for (int j = 0; j < 24; j++) {
            std::cout << j << std::endl;
            if (this->row + 1 == (pieces + j)->getRow() && this->col + i == (pieces + j)->getCol() &&
                this->red == (pieces + j)->getRed()) {
		puts("b1");
                //same place same team
                *(possibleMoves + k++) = *noMove;
                puts("b");
            } else if (this->row + 1 != (pieces + j)->getRow() && this->col + i != (pieces + j)->getCol() &&
                       (this->row + 1 < 8 && this->col + i < 8 && this->col + i > -1)) {
                //valid move with no jump or anything like that
		puts("c1");
                CheckerPiece::PossibleMove *move = (PossibleMove * )(malloc(sizeof(PossibleMove)));
                move->newPiece = new Pawn(this->row + 1, this->col + i, this->red);
                move->jump = false;
                move->numJumped = -1;
                move->king = false;
                *(possibleMoves + k++) = *move;
                free(move);
                puts("c");
            } else if (this->row + 1 == (pieces + j)->getRow() && this->col + i == (pieces + j)->getCol() &&
                       this->red != (pieces + j)->getRed()) {
		puts("d1");
                //same space different team with +/-1(Possible jump)
                if ((this->row == 6 && !(this->red)) || (this->row == 1 && (this->red))) {
                    //jump would be off the board
                    *(possibleMoves + k++) = *noMove;
                } else if (((this->row == 5 && !(this->red)) || (this->row == 2 && (this->red))) &&
                           (this->col + (i * 2) <= 7 && this->col + (i * 2) >= 0)) {
                    //valid jump into king
                    CheckerPiece::PossibleMove *move = (PossibleMove * )(malloc(sizeof(PossibleMove)));
                    move->newPiece = new King(this->row + (1 * 2), this->col + (2 * i), this->red);
                    move->jump = true;
                    move->numJumped = j;
                    move->king = true;
                    *(possibleMoves + k++) = *move;
                    free(move);
                } else {
                    //valid jump but not a king
                    CheckerPiece::PossibleMove *move = (PossibleMove * )(malloc(sizeof(PossibleMove)));
                    move->newPiece = new Pawn(this->row + (1 * 2), this->col + (2 * i), this->red);
                    move->jump = true;
                    move->numJumped = j;
                    move->king = false;
                    *(possibleMoves + k++) = *move;
                    free(move);
                }
                puts("d");
            } else {
                *(possibleMoves + k++) = *noMove;
		puts("e");
            }
        }
    }
    free(noMove);
    puts("endMethod");
    return possibleMoves;
}
