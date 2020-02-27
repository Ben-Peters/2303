//
// Created by Ben on 2/25/2020.
//

#ifndef HW4_LINKEDLIST_H
#define HW4_LINKEDLIST_H

#include "Room.h"
#include <iostream>
#include <fstream>
using namespace std;



class LinkedList {
public:
    typedef struct {
        int roomNumber;
        float treasure;
    } SearchResults;
    typedef Room Payload;
    typedef SearchResults Payload2;
    class LinkedListNode2{
    public:
        LinkedListNode2* next;
        LinkedListNode2* prev;
        Payload2* payP;
    };
    class LinkedListNode{
        public:
                LinkedListNode* next;
                LinkedListNode* prev;
                Payload* payP;
    };
    typedef struct {
        Payload *mp;
        LinkedListNode *newQHead;
    } backFromDQFIFO;
    LinkedList();
    virtual ~LinkedList();
    static LinkedListNode* makeEmptyLinkedList();
    static LinkedListNode2* makeEmptyLinkedList2();
    static LinkedListNode * removeFromList(LinkedListNode *hp, Payload *pP);
    static void savePayload(LinkedListNode *lp, Payload *mp);
    static void savePayload2(LinkedListNode2 *lp, Payload2 *mp);
    static bool isEmpty(LinkedListNode *lp);
    static bool isEmpty2(LinkedListNode2 *lp);
    static Payload *dequeueLIFO(LinkedListNode *lp);
    static backFromDQFIFO *dequeueFIFO(LinkedListNode *lp);
    static void printHistory(LinkedListNode2 *hp);

};


#endif //HW4_LINKEDLIST_H
