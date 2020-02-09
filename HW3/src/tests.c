/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"


bool tests()
{
	bool answer = false;
	bool ok1 = testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
	return answer;
}

bool testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = false;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;


	AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
	Room* theRoomPs[10];//addresses for 10 rooms


	ok = readFile("../houseGraph.txt", &answer, adjMP, theRoomPs); //read the file
    if(ok)
	{
		if(answer!=rightAnswer)
		{
			puts("test failed on number of rooms");
		}

	}
	puts("The adjacency matrix");
	for(int i = 0; i<answer; i++)
	{
		for(int j = 0; j<answer; j++)
		{
			printf("%d",getEdge(adjMP, i, j));

		}
		printf("\n");
	}
	puts("The treasure values");
	for(int i = 0; i<answer; i++)
	{
		printf("%f\n", theRoomPs[i]->treasure);
	}

    //fclose("houseGraph.txt");
	return ok;
}

bool testGotAdjacencyMatrix()
{
	bool ans = true;
    AdjMat* realAdjMP = (AdjMat*) malloc(sizeof(AdjMat));
    AdjMat* testAdjMP = (AdjMat*) malloc(sizeof(AdjMat));
    Room* theRoomPs[10];
    int howManyRooms = 8;
    realAdjMP -> n = howManyRooms;
    realAdjMP->edgesP = (int*) malloc(howManyRooms * howManyRooms *sizeof(int));
    init(realAdjMP);
    setEdge(realAdjMP, 1, 0);
    setEdge(realAdjMP, 2, 1);
    setEdge(realAdjMP, 3, 0);
    setEdge(realAdjMP, 3, 2);
    setEdge(realAdjMP, 4, 1);
    setEdge(realAdjMP, 4, 3);
    setEdge(realAdjMP, 5, 0);
    setEdge(realAdjMP, 5, 2);
    setEdge(realAdjMP, 6, 1);
    setEdge(realAdjMP, 6, 2);
    setEdge(realAdjMP, 6, 5);
    setEdge(realAdjMP, 7, 0);
    setEdge(realAdjMP, 7, 1);
    setEdge(realAdjMP, 7, 2);
    setEdge(realAdjMP, 7, 4);
    int numRooms = 8;
    readFile("/Users/Tom/Projects/CS/CS2303/2303/HW3/houseGraph.txt", &numRooms, testAdjMP, theRoomPs);
    for(int i = 0; i < numRooms; i++){
        for(int j = 0; j < numRooms; j++){
            if(getEdge(realAdjMP,i,j) != getEdge(testAdjMP,i,j)){
                ans = false;
            }
        }
    }
    if(!ans){
        puts("Fail: Got Adjacency Matrix");
    }
    else{
        puts("Pass: Got Adjacency Matrix");
    }
	return ans;
}

bool testMakeLList()
{
	bool ok = true;
	puts("starting testMakeLList");fflush(stdout);
	//what are the criteria for success for make LList?
	//should be able to make one, add data to it, get the data back
	//test case 1:
	LLNode* theListP = makeEmptyLinkedList();
	bool rightAnswer = true;
	bool answer = isEmpty(theListP);
	Room** room = (Room*) malloc(sizeof(Room));
	savePayload(theListP, room);
	if(answer!=rightAnswer)
	{
		ok = false;
	}
	//test case 2:
	if (theListP->payP != room){
	    ok = false;
	    puts("Fail: Unable to add room to linkedList");
	}
	Room** room2 = (Room*) malloc(sizeof(Room));
	savePayload(theListP, room2);
	LLNode* nextElement = theListP->next;
	if (theListP->next == (struct LLNode*)0 || nextElement->prev != theListP){
	    ok = false;
	    puts("Fail: Unable to add multiple items to linkedList");
	}
	if (ok){
	    puts("Pass: LinkedLists were processed successfully");
	}

	return ok;
}
bool testRemoveFromList()
{
	bool ok = true;
	//cases:
	//1 list is empty:return same list
	//2 list is of length one, and item is present: return empty list
	//3 list is of length one, and item is not present: return same list
	//4 list is longer than one, item is present, at first location: return list starting at second element
	//5 list is longer than one, item is present, not at first location: return list with item removed
	//6 list is longer than one, item is not present: return same list
	LLNode* case1 = makeEmptyLinkedList();
	Payload* pay1 = (Payload*) malloc(sizeof(Room));
	pay1->roomNumber = 1;
	LLNode* ans = removeFromList(case1, pay1);
	if((ans != case1) || (ans->payP != (Payload*)0))
	{
		ok = false;

	}
	printf("testRemove case 1 with %d\n", ok); fflush(stdout);
	savePayload(case1, pay1);
	//this is case2
	ans = removeFromList(case1, pay1);
	if((ans != case1) || (ans->payP != (Payload*)0))
	{
		ok = false;

	}
	printf("testRemove case 2 with %d\n", ok); fflush(stdout);
	//now case 3
	Payload* pay3 = (Payload*) malloc(sizeof(Room));
	pay3->roomNumber = 3;
	ans = removeFromList(case1, pay3);
	if(ans != case1)//this is only a partial check for list unchanged
	{
		ok = false;

	}
	printf("testRemove case 3 with %d\n", ok); fflush(stdout);
	//now case 4
	case1 = makeEmptyLinkedList();
	pay1 = (Payload*) malloc(sizeof(Room));
	pay1->roomNumber = 1;
	savePayload(case1, pay1);
	pay3 = (Payload*) malloc(sizeof(Room));
	pay3->roomNumber = 3;
	savePayload(case1, pay3);
	ans = removeFromList(case1, pay1);

	if(ans == case1)
	{
		ok = false;

	}
	printf("testRemove case 4 with %d\n", ok); fflush(stdout);
	//now case 5
	case1 = makeEmptyLinkedList();
	pay1 = (Payload*) malloc(sizeof(Room));
	pay1->roomNumber = 1;
	savePayload(case1, pay1);
	pay3 = (Payload*) malloc(sizeof(Room));
	pay3->roomNumber = 3;
	savePayload(case1, pay3);
	//puts("trying case 5");fflush(stdout);
	ans = removeFromList(case1, pay3);//ans should be equal to case1
	LLNode* theNext = (LLNode*) ans->next; //this is element where pay3 got attached
	Payload* check = (Payload*) 0;
	if (theNext)
	{
		check = theNext->payP; //this should be pay3, which should have been removed
	}
	//printf("testRemove returned from case 5\n"); fflush(stdout);
	if((ans != case1) || (check != (Payload*)0))//disquiet
	{
		ok = false;

	}
	//printf("ans == case1 is %d\n", ans==case1);
	//printf("check != 0 is %d\n", check != (Payload*)0);
	printf("testRemove case 5 with %d\n", ok); fflush(stdout);
	//now case 6
	case1 = makeEmptyLinkedList();
	pay1 = (Payload*) malloc(sizeof(Room));
	pay1->roomNumber = 1;
	savePayload(case1, pay1);
	pay3 = (Payload*) malloc(sizeof(Room));
	pay3->roomNumber = 3;
	savePayload(case1, pay3);
	Payload* another = (Payload*) malloc(sizeof(Room));
	another->roomNumber=2;
	ans = removeFromList(case1, another);
	if((ans != case1))
	{
		ok = false;

	}
	printf("testRemove case 6 with %d\n", ok); fflush(stdout);
	return ok;
}
bool testPrintHistory()
{
	bool ok = true;
	return ok;
}

bool testEnqueue(){
    return false;
}
