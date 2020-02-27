//
// Created by Ben on 2/25/2020.
//

#ifndef HW4_LINKEDLIST_H
#define HW4_LINKEDLIST_H

#include "Room.h"



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
    LinkedListNode* makeEmptyLinkedList();
    LinkedListNode2* makeEmptyLinkedList2();
    LinkedListNode * removeFromList(LinkedListNode *hp, Payload *pP);
    void savePayload(LinkedListNode *lp, Payload *mp);
    void savePayload2(LinkedListNode2 *lp, Payload2 *mp);
    bool isEmpty(LinkedListNode *lp);
    bool isEmpty2(LinkedListNode2 *lp);
    Payload *dequeueLIFO(LinkedListNode *lp);
    backFromDQFIFO *dequeueFIFO(LinkedListNode *lp);
    void printHistory(LinkedListNode2 *hp);

};


#endif //HW4_LINKEDLIST_H
