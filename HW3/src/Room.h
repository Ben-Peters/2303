/*
 * Room.h
 *
 *  Created on: Oct 29, 2019
 *      Author: Therese
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <stdbool.h>

typedef struct
{
	int roomNumber;
	float treasure;
	bool searched;
}Room;

#endif /* ROOM_H_ */
