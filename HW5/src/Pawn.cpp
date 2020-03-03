//
// Created by Ben on 2/29/2020.
//

#include "Pawn.h"

Pawn::Pawn(int row, int col, bool red) : CheckerPiece(row, col, red) {
    this->row = row;
    this->col = col;
    this->red = red;
}

Pawn::~Pawn() {}

CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *board) {
    return nullptr;
}
