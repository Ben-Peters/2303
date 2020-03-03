//
// Created by Ben on 2/29/2020.
//

#include "King.h"

King::King(int row, int col, bool red) : CheckerPiece(row, col, red) {
    this->row = row;
    this->col = col;
    this->red = red;
}

King::~King() {}

CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *board) {
    return nullptr;
}