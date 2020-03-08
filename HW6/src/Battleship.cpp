//
// Created by Tom Nurse on 3/7/20.
//

#include "Battleship.h"

Battleship::Battleship():Ship(size, id, sunk) {
    this->size = 4;
    this->id = 'b';
    this->sunk = false;
}

Battleship::~Battleship() {

}