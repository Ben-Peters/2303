/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "display.h"
#include "marker.h"
#include "LinkedList.h"
#include "space.h"

bool production(int argc, char* argv[])
{

//=====================================================================
//This section remains only so that we "don't touch the starter code"
//Aside from that, what it does is completely unnecessary to program
//function and serves only to waste space, processing power, etc.
//So I'm including it, but under protest.
//
// --Alexander
//
	bool answer = true;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		int maxRooms;
		int maxTreasure;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
			switch(i)
			{
			case 1:
				//this is filename
				printf("The length of the filename is %d.\n",strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 2:
				//this is maximum number of rooms

				aL= strtol(argv[i], &eptr, 10);
				maxRooms = (int) aL;
				if(maxRooms <0)
				{
					answer = false;
				}
				printf("Number of rooms is %d\n",maxRooms);fflush(stdout);
				break;
			case 3:
				//this is maximum amount of treasure

				aL= strtol(argv[i], &eptr, 10);
				maxTreasure = (int) aL;
				if(maxTreasure <0)
				{
					answer = false;
				}
				printf("Amount of treasure is %d\n",maxTreasure);fflush(stdout);
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);

	}//end of command line arguments

//=====================================================================

	//obtain space for 20x20 of integers
	int size = 20;
	int* theSpaceP = (int*) malloc(size*size*sizeof(int));
	initSpace(theSpaceP, size);
	//init the LL
	LLNode* ll = makeEmptyLinkedList();
	//make the inital marker
	int* coords = getRandCoordinates();
	Marker* mP = placeMarker(coords[0], coords[1]);
	mP->index = 1;
	savePayload(ll, mP);
	
	updateSpace(theSpaceP, size, mP->row, mP->col, mP->index);
	puts("Step 1:");
	print2DArrayWithoutZero(theSpaceP, size);

	for(int idx = 2; idx < 21; idx++) {
		mP = makeAdjacentMarker(mP, idx);
		savePayload(ll, mP);
		
		updateSpace(theSpaceP, size, mP->row, mP->col, mP->index);
		printf("Step %d:\n", idx);
		print2DArrayWithoutZero(theSpaceP, size);
	}
	traverseAndPrint(ll, true);

	//we'll want to read the file
	return true;
}


