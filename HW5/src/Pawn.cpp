//
// Created by Ben on 2/29/2020.
//

#include "Pawn.h"

Pawn::Pawn() {}

Pawn::~Pawn() {}

int Pawn::getRow() {
    return row;
}

int Pawn::getCol() {
    return col;
}

bool Pawn::getRed() {
    return red;
}

void Pawn::setRow(int value) {
    row = value;
}

void Pawn::setCol(int value) {
    col = value;
}

void Pawn::setRed(bool value) {
    red = value;
}

int *Pawn::getAllPossibleMoves(){
    return &row;
}