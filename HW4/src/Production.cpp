/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include <stdbool.h>

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}
bool Production::prod(int argc, char* argv[])
{
    bool answer = false;

    if(argc <=1) //no interesting information
    {
        cout <<("Didn't find any arguments.");
        fflush(stdout);
        answer = false;
    }
    else //there is interesting information
    {
        printf("Found %d interesting arguments.\n", argc-1);
        fflush(stdout);
        char filename[FILENAMELENGTHALLOWANCE];
        char* eptr=(char*) malloc(sizeof(char*));
        long aL=-1L;
        int maxRooms = -1;
        float maxTreasure = -1;
        double maxTreas;
        for(int i = 1; i<argc; i++) //don't want to read argv[0]
        {//argv[i] is a string
            //in this program our arguments are NR, NC, gens, filename, print and pause
            //because pause is optional, argc could be 6 or 7
            //because print is optional (if print is not present, neither is pause) argc could be 5
            switch(i)
            {
                case 1:
                    //this is filename
                    printf("The length of the filename is %lu.\n",strlen(argv[i]));
                    printf("The proposed filename is %s.\n", argv[i]);
                    if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
                    {
                        cout <<("Filename is too long.");
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
                    printf("Number of rooms is %d\n",maxRooms);fflush(stdout);
                    break;
                case 3:
                    //this is maximum amount of treasure

                    maxTreas = atof(argv[i]);
                    printf("Amount of  treasure is %f\n",maxTreas);fflush(stdout);
                    maxTreasure = (float) maxTreas;
                    break;

                default:
                    cout <<("Unexpected argument count."); fflush(stdout);
                    answer = false;
                    break;
            }//end of switch
        }//end of for loop on argument count
        cout <<("after reading arguments"); fflush(stdout);

        if(maxRooms == -1)
            maxRooms = promptNumOfRooms();
        if(maxTreasure == -1)
            maxTreasure = promptAmountTreasure();


        //we'll want to read the file
        int nrooms = -1;
        AdjMatrix::AdjMat* adjMP = (AdjMatrix::AdjMat*) malloc(sizeof(AdjMatrix::AdjMat));
        //cannot, do not know nrooms init(adjMP);
        //cout <<("Back from init Adj Mat"); fflush(stdout);
        Room* theRoomPs[10];//addresses for 10 rooms

        cout <<("Before read file"); fflush(stdout);
        answer = readFile(filename, &nrooms, adjMP, theRoomPs); //read the file
        cout <<("Back from read file"); fflush(stdout);

        //we'll want to conduct the search
        //for the search we'll need an empty search history
        LinkedList::LinkedListNode2* historyP = LinkedList::makeEmptyLinkedList2();
        //we'll need the Queue, into which we put rooms, and remove rooms
        LinkedList::LinkedListNode* searchQ = LinkedList::makeEmptyLinkedList();
        cout <<("starting search"); fflush(stdout);
        //we'll start searching with room 0
        bool done = false;
        int searchedRooms = 0;
        float foundTreasure = 0.0;
        Room* roomBeingSearchedP = theRoomPs[0];
        //we set its searched field to true, and take its treasure
        roomBeingSearchedP->searched = true;
        //we record it in the history
        LinkedList::SearchResults* srP = (LinkedList::SearchResults*) malloc(sizeof(LinkedList::SearchResults));
        srP->roomNumber= 0;
        srP->treasure = roomBeingSearchedP->treasure;
        if((srP->treasure <= maxTreas) && (maxRooms>0))
        {
            //here we are enqueueing room 0
            cout <<("Enqueuing room 0");
            LinkedList::savePayload(searchQ, roomBeingSearchedP);

        }

        while(!done)
        {   //here we want to find all of the rooms adjacent to the roomBeingSearched,
            //so we look in the adj matrix
            for(int col = 0; (col<nrooms)&&!done; col++)
            {
                //we check whether this room is neighboring
                printf("checking rooms %d and %d.\n", roomBeingSearchedP->roomNumber, col); fflush(stdout);
                if(AdjMatrix::getEdge(adjMP,roomBeingSearchedP->roomNumber, col)==1)
                {
                    cout <<("found an edge"); fflush(stdout);
                    //if so, we check whether room has been searched
                    if(!(theRoomPs[col]->searched))
                    {//if it hasn't been searched
                        printf("Room %d hasn't already been searched.\n", col);
                        //we set it to searched
                        theRoomPs[col]->searched=true;
                        if(!done)
                            //we check whether we can take the treasure vs. limit
                            //we check whether we've hit the room limit
                        {//we enqueue it for search
                            foundTreasure += roomBeingSearchedP->treasure;
                            searchedRooms += 1;
                            printf("found treasure updated to %f.\n", foundTreasure);
                            printf("enqueuing room %d.\n", col); fflush(stdout);
                            printf("Before enqueuing queue empty reports %d\n", LinkedList::isEmpty(searchQ));
                            LinkedList::savePayload(searchQ,roomBeingSearchedP);
                            srP = (LinkedList::SearchResults*) malloc(sizeof(LinkedList::SearchResults));
                            srP->roomNumber=theRoomPs[col]->roomNumber;
                            srP->treasure = theRoomPs[col]->treasure;
                            LinkedList::savePayload2(historyP,srP);
                            printf("After enqueuing, queue empty reports %d\n", LinkedList::isEmpty(searchQ));
                        }//check about search limits
                    }//room can still be searched
                }//room is a neighbor

                if(foundTreasure >= maxTreasure)
                {
                    done = true;
                    cout <<("Done by treasure");
                }
                if (searchedRooms>=maxRooms)
                {
                    done = true;
                    cout <<("Done by rooms");
                }
            }//scan for all possible rooms to search from this room
            //time to get the next room
            if(LinkedList::isEmpty(searchQ))
            {
                done=true;
                cout <<("Done by queue empty");
            }
            if(!done)
            {
                cout <<("Invoking  dequeue");fflush(stdout);
                roomBeingSearchedP = LinkedList::dequeueLIFO(searchQ);

            }
        }//while search is not done
        //search is now done, time to print the history
        LinkedList::printHistory(historyP);


    }//end of else we have good arguments

    return answer;
}
bool readFile(char* filename, int* nrooms, AdjMatrix::AdjMat* adjMP, Room** theRoomPs)
{
    bool ok = false;
    //the file tells how many rooms there are
    FILE* fp = fopen(filename, "r"); //read the file

    if (fp == NULL)
    {
        cout <<("Error! opening file");

    }
    else
    {
        fscanf(fp,"%d", nrooms);
        adjMP->n=*nrooms;
        int howManyRooms = *nrooms;
        adjMP->edgesP = (int*) malloc(howManyRooms * howManyRooms *sizeof(int));
        cout <<("Before init Adj Mat"); fflush(stdout);
        AdjMatrix::init(adjMP);
        int temp = -1;
        for(int roomr = 1; roomr<*nrooms; roomr++)
        {
            printf("on row %d\n", roomr);fflush(stdout);
            for(int roomc = 0; roomc<roomr; roomc++)
            {
                fscanf(fp,"%d", &temp);
                printf("in column %d, read %d\n", roomc, temp);fflush(stdout);
                //now set the value in the adjacency matrix
                if(temp==1)
                {
                    AdjMatrix::setEdge(adjMP, roomr, roomc);
                }

            }
        }

        float tempTreas = 2.9;
        for(int roomr = 0; roomr<*nrooms; roomr++)
        {
            fscanf(fp,"%f", &tempTreas);
            //make a room and set its treasure
            Room** aRoomP = theRoomPs;
            aRoomP = aRoomP+roomr;
            *aRoomP = (Room*) malloc(sizeof(Room));
            //now set the treasures
            (*aRoomP)->treasure = tempTreas;
            (*aRoomP)->roomNumber = roomr;
            printf("The treasure in room %d is %f\n", roomr, (*aRoomP)->treasure);
        }
        ok = true;
    }
    fclose(fp);

    return ok;
}

int promptNumOfRooms(){
    int rooms = 0;
    printf("Enter the number of rooms to search: ");
    scanf("%d", &rooms);
    return rooms;
}

float promptAmountTreasure(){
    float treasure = 0;
    printf("Enter the max amount of treasure to search for: ");
    scanf("%f", &treasure);
    return treasure;
}


