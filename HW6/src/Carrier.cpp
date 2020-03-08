//
// Created by Tom Nurse on 3/7/20.
//

#include "Carrier.h"

Carrier::Carrier():Ship(size, id, sunk) {
    this->size = 5;
    this->id = 'c';
    this->sunk = false;
}

Carrier::~Carrier() {

}