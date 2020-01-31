//
// Created by Ben on 1/31/2020.
//

#ifndef HW1_ROOM_H
#define HW1_ROOM_H

#include <stdbool.h>
typedef struct{
    bool locked;
    bool treasure;
    int amountOfTreasure;
}Room;
bool open(Room);
#endif //HW1_ROOM_H
