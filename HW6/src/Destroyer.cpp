//
// Created by Tom Nurse on 3/7/20.
//

#include "Destroyer.h"

Destroyer::Destroyer():Ship(size, id, sunk) {
    this->size = 2;
    this->id = 'd';
    this->sunk = false;
}

Destroyer::~Destroyer() {

}