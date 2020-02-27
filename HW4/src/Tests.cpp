/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include <iostream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}
/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"



bool Tests::tests()
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

bool Tests::testReadFile()
{
    cout << "starting testReadFile"<<endl; fflush(stdout);
    bool ok = false;
    //the file tells how many rooms there are
    int answer = -1;
    int rightAnswer = 8;


    AdjMatrix::AdjMat* adjMP = (AdjMatrix::AdjMat*) malloc(sizeof(AdjMatrix::AdjMat));
    Room* theRoomPs[10];//addresses for 10 rooms


    ok = Production::readFile("../houseGraph.txt", &answer, adjMP, theRoomPs); //read the file
    if(ok)
    {
        if(answer!=rightAnswer)
        {
            cout <<("test failed on number of rooms");
        }

    }
    cout <<("The adjacency matrix");
    for(int i = 0; i<answer; i++)
    {
        for(int j = 0; j<answer; j++)
        {
            printf("%d",AdjMatrix::getEdge(adjMP, i, j));

        }
        printf("\n");
    }
    cout <<("The treasure values");
    for(int i = 0; i<answer; i++)
    {
        printf("%f\n", theRoomPs[i]->Room::treasure);
    }

    //fclose("houseGraph.txt");
    return ok;
}

bool Tests::testGotAdjacencyMatrix()
{
    bool ans = true;
    AdjMatrix::AdjMat* realAdjMP = (AdjMatrix::AdjMat*) malloc(sizeof(AdjMatrix::AdjMat));
    AdjMatrix::AdjMat* testAdjMP = (AdjMatrix::AdjMat*) malloc(sizeof(AdjMatrix::AdjMat));
    Room* theRoomPs[10];
    int howManyRooms = 8;
    realAdjMP -> n = howManyRooms;
    realAdjMP->edgesP = (int*) malloc(howManyRooms * howManyRooms *sizeof(int));
    AdjMatrix::init(realAdjMP);
    AdjMatrix::setEdge(realAdjMP, 1, 0);
    AdjMatrix::setEdge(realAdjMP, 2, 1);
    AdjMatrix::setEdge(realAdjMP, 3, 0);
    AdjMatrix::setEdge(realAdjMP, 3, 2);
    AdjMatrix::setEdge(realAdjMP, 4, 1);
    AdjMatrix::setEdge(realAdjMP, 4, 3);
    AdjMatrix::setEdge(realAdjMP, 5, 0);
    AdjMatrix::setEdge(realAdjMP, 5, 2);
    AdjMatrix::setEdge(realAdjMP, 6, 1);
    AdjMatrix::setEdge(realAdjMP, 6, 2);
    AdjMatrix::setEdge(realAdjMP, 6, 5);
    AdjMatrix::setEdge(realAdjMP, 7, 0);
    AdjMatrix::setEdge(realAdjMP, 7, 1);
    AdjMatrix::setEdge(realAdjMP, 7, 2);
    AdjMatrix::setEdge(realAdjMP, 7, 4);
    int numRooms = 8;
    Production::readFile("../houseGraph.txt", &numRooms, testAdjMP, theRoomPs);
    for(int i = 0; i < numRooms; i++){
        for(int j = 0; j < numRooms; j++){
            if(AdjMatrix::getEdge(realAdjMP,i,j) != AdjMatrix::getEdge(testAdjMP,i,j)){
                ans = false;
            }
        }
    }
    if(!ans){
        cout <<("Fail: Got Adjacency Matrix");
    }
    else{
        cout <<("Pass: Got Adjacency Matrix");
    }
    return ans;
}

bool Tests::testMakeLList()
{
    bool ok = true;
    cout <<("starting testMakeLList");fflush(stdout);
    //what are the criteria for success for make LList?
    //should be able to make one, add data to it, get the data back
    //test case 1:
    LinkedList::LinkedListNode *theListP;
    theListP = LinkedList::makeEmptyLinkedList();
    bool rightAnswer = true;
    bool answer = LinkedList::isEmpty(theListP);
    Room* room = (Room*) malloc(sizeof(Room));
    LinkedList::savePayload(theListP, room);
    if(answer!=rightAnswer)
    {
        ok = false;
    }
    //test case 2:
    if (theListP->payP != room){
        ok = false;
        cout <<("Fail: Unable to add room to linkedList");
    }
    Room* room2 = (Room*) malloc(sizeof(Room));
    LinkedList::savePayload(theListP, room2);
    LinkedList::LinkedListNode* nextElement = theListP->next;
    if (theListP->next == (LinkedList::LinkedListNode*)0 || nextElement->prev != theListP){
        ok = false;
        cout <<("Fail: Unable to add multiple items to linkedList");
    }
    if (ok){
        cout <<("Pass: Test MakeLList, LinkedLists were processed successfully");
    }

    return ok;
}
bool Tests::testRemoveFromList()
{
    bool ok = true;
    //cases:
    //1 list is empty:return same list
    //2 list is of length one, and item is present: return empty list
    //3 list is of length one, and item is not present: return same list
    //4 list is longer than one, item is present, at first location: return list starting at second element
    //5 list is longer than one, item is present, not at first location: return list with item removed
    //6 list is longer than one, item is not present: return same list
    LinkedList::LinkedListNode* case1 = LinkedList::makeEmptyLinkedList();
    LinkedList::Payload* pay1 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay1->roomNumber = 1;
    LinkedList::LinkedListNode* ans = LinkedList::removeFromList(case1, pay1);
    if((ans != case1) || (ans->payP != (LinkedList::Payload*)0))
    {
        ok = false;

    }
    printf("testRemove case 1 with %d\n", ok); fflush(stdout);
    LinkedList::savePayload(case1, pay1);
    //this is case2
    ans = LinkedList::removeFromList(case1, pay1);
    if((ans != case1) || (ans->payP != (LinkedList::Payload*)0))
    {
        ok = false;

    }
    printf("testRemove case 2 with %d\n", ok); fflush(stdout);
    //now case 3
    LinkedList::Payload* pay3 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay3->roomNumber = 3;
    ans = LinkedList::removeFromList(case1, pay3);
    if(ans != case1)//this is only a partial check for list unchanged
    {
        ok = false;

    }
    printf("testRemove case 3 with %d\n", ok); fflush(stdout);
    //now case 4
    case1 = LinkedList::makeEmptyLinkedList();
    pay1 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay1->roomNumber = 1;
    LinkedList::savePayload(case1, pay1);
    pay3 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay3->roomNumber = 3;
    LinkedList::savePayload(case1, pay3);
    ans = LinkedList::removeFromList(case1, pay1);

    if(ans == case1)
    {
        ok = false;

    }
    printf("testRemove case 4 with %d\n", ok); fflush(stdout);
    //now case 5
    case1 = LinkedList::makeEmptyLinkedList();
    pay1 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay1->roomNumber = 1;
    LinkedList::savePayload(case1, pay1);
    pay3 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay3->roomNumber = 3;
    LinkedList::savePayload(case1, pay3);
    //cout <<("trying case 5");fflush(stdout);
    ans = LinkedList::removeFromList(case1, pay3);//ans should be equal to case1
    LinkedList::LinkedListNode* theNext = (LinkedList::LinkedListNode*) ans->next; //this is element where pay3 got attached
    LinkedList::Payload* check = (LinkedList::Payload*) 0;
    if (theNext)
    {
        check = theNext->payP; //this should be pay3, which should have been removed
    }
    //printf("testRemove returned from case 5\n"); fflush(stdout);
    if((ans != case1) || (check != (LinkedList::Payload*)0))//disquiet
    {
        ok = false;

    }
    //printf("ans == case1 is %d\n", ans==case1);
    //printf("check != 0 is %d\n", check != (Payload*)0);
    printf("testRemove case 5 with %d\n", ok); fflush(stdout);
    //now case 6
    case1 = LinkedList::makeEmptyLinkedList();
    pay1 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay1->roomNumber = 1;
    LinkedList::savePayload(case1, pay1);
    pay3 = (LinkedList::Payload*) malloc(sizeof(Room));
    pay3->roomNumber = 3;
    LinkedList::savePayload(case1, pay3);
    LinkedList::Payload* another = (LinkedList::Payload*) malloc(sizeof(Room));
    another->roomNumber=2;
    ans = LinkedList::removeFromList(case1, another);
    if((ans != case1))
    {
        ok = false;

    }
    printf("testRemove case 6 with %d\n", ok); fflush(stdout);
    return ok;
}
bool Tests::testPrintHistory()
{
    bool ok = false;
    LinkedList::LinkedListNode2* list = LinkedList::makeEmptyLinkedList2();
    LinkedList::SearchResults* srP = (LinkedList::SearchResults*) malloc(sizeof(LinkedList::SearchResults));
    srP->roomNumber= 1;
    srP->treasure = 1.25;
    LinkedList::savePayload2(list, srP);
    LinkedList::printHistory(list);
    cout <<("Is the last line printed \"The room was 1, and the treasure subtotal was 1.250000.\" (y/n)");
    char input;
    scanf("%c",&input);
    if(input == 'y'){
        ok = true;
    }
    if(ok){
        cout <<("Pass: testPrintHistory");
    }
    else{
        cout <<("Fail: testPrintHistory");
    }
    return ok;
}

bool Tests::testEnqueue(){
    bool ok = false;
    LinkedList::LinkedListNode* list = LinkedList::makeEmptyLinkedList();
    Room *rP = (Room*) malloc(sizeof(Room));
    rP -> roomNumber = 1;
    rP -> searched = false;
    rP -> treasure = 1.23;
    LinkedList::Payload* roomPay = rP;
    list->payP = roomPay;

    // Function to test
    LinkedList::LinkedListNode* list2 = LinkedList::makeEmptyLinkedList();
    LinkedList::savePayload(list2, rP);

    if (list2->payP == list->payP){
        ok = true;
        cout <<("Pass: test enqueue");
    }else{
        cout <<("Failed to add element to linked list");
    }
    return ok;
}


