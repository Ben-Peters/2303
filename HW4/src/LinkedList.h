//
// Created by Ben on 2/25/2020.
//

#ifndef HW4_LINKEDLIST_H
#define HW4_LINKEDLIST_H

#include "Room.h"

class LinkedList {
    typedef struct
    {
        int roomNumber;
        float treasure;
    }SearchResults;
    typedef Room Payload;
    typedef SearchResults Payload2;
    struct LLNode;
    typedef struct
    {
        struct LLNode* next;
        struct LLNode* prev;
        Payload* payP;
    }LLNode;
    typedef struct
    {
        struct LLNode2* next;
        struct LLNode2* prev;
        Payload2* payP;
    }LLNode2;

    typedef struct
    {
        Payload* mp;
        LLNode* newQHead;
    }backFromDQFIFO;

    LLNode* makeEmptyLinkedList();
    LLNode2* makeEmptyLinkedList2();
    LLNode* removeFromList(LLNode* hp, Payload* pP);
    void savePayload(LLNode* lp, Payload* mp);
    void savePayload2(LLNode2* lp, Payload2* mp);
    bool isEmpty(LLNode* lp);
    Payload* dequeueLIFO(LLNode* lp);
    backFromDQFIFO* dequeueFIFO(LLNode* lp);
    void printHistory(LLNode2* hp);
};


#endif //HW4_LINKEDLIST_H
