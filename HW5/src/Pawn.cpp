//
// Created by Ben on 2/29/2020.
//

#include "Pawn.h"

Pawn::Pawn() {}

Pawn::Pawn(bool isRed, int irow, int icol) {
    red = isRed;
    col = icol;
    row = irow;
}

Pawn::~Pawn() {}

CheckerPiece *Pawn::getAllPossibleMoves() {
    return this;
}
