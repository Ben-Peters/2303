//
// Created by Tom Nurse on 3/7/20.
//

#include "Sub.h"

Sub::Sub():Ship(size, id, sunk) {
    this->size = 3;
    this->id = 's';
    this->sunk = false;
}

Sub::~Sub() {

}