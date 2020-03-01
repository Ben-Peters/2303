//
// Created by Ben on 2/29/2020.
//

#include "King.h"
King::King() {}

King::~King() {}

int King::getRow() {
    return row;
}

int King::getCol() {
    return col;
}

bool King::getRed() {
    return red;
}

void King::setRow(int value) {
    row = value;
}

void King::setCol(int value) {
    col = value;
}

void King::setRed(bool value) {
    red = value;
}

int *King::getAllPossibleMoves(){
    return &row;
}