//
// Created by Ben on 3/2/2020.
//

#include "CheckerPiece.h"
CheckerPiece::CheckerPiece() {}

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

void CheckerPiece::setRow(int value) {
    row = value;
}

void CheckerPiece::setCol(int value) {
    col = value;
}

void CheckerPiece::setRed(bool value) {
    red = value;
}

CheckerPiece *CheckerPiece::getAllPossibleMoves(){
    return this;
}