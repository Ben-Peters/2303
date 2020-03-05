//
// Created by Ben on 3/2/2020.
//

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

}

King::King(int row, int col, bool red) : CheckerPiece(row, col, red) {
    this->row = row;
    this->col = col;
    this->red = red;
}

King::~King() {}

CheckerPiece::PossibleMove *King::getAllPossibleMoves(CheckerPiece *) {
    return nullptr;
}

Pawn::Pawn(int row, int col, bool red) : CheckerPiece(row, col, red) {
    this->row = row;
    this->col = col;
    this->red = red;
}

Pawn::~Pawn() {}

CheckerPiece::PossibleMove *Pawn::getAllPossibleMoves(CheckerPiece *board) {
    return nullptr;
}
