//
// Created by Tom on 3/8/20.
//

#include "Cruiser.h"

Cruiser::Cruiser():Ship(size, id, sunk) {
    this->size = 3;
    this->id = 'u';
    this->sunk = false;
}

Cruiser::~Cruiser() {

}