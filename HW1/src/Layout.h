//
// Created by Ben on 1/26/2020.
//

#ifndef HW1_LAYOUT_H
#define HW1_LAYOUT_H


#include <stdbool.h>

typedef struct{
    bool locked;
    bool treasure;
    int amountOfTreasure;
}Room;
bool open(Room);
#endif //HW1_LAYOUT_H
