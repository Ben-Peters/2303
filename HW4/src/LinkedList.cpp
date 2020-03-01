//
// Created by Ben on 2/25/2020.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
    LinkedList::LinkedList() {
}
    LinkedList::~LinkedList() {

}
    bool LinkedList::isEmpty(LinkedListNode *lp) {
        bool ans = false;
        if (lp->payP == (Payload *) 0) {
            ans = true;
        }
        return ans;
    }

    bool LinkedList::isEmpty2(LinkedListNode2 *lp) {
        bool ans = false;
        if (lp->payP == (Payload2 *) 0) {
            ans = true;
        }
        return ans;
    }

    LinkedList::LinkedListNode* LinkedList::makeEmptyLinkedList()
    {
        LinkedListNode* lp = (LinkedListNode*) malloc(sizeof(LinkedListNode));
        lp->next = (LinkedListNode*)0;
        lp->prev = (LinkedListNode*)0;
        lp->payP = (Payload*)0;

        return lp;
    }

    LinkedList::LinkedListNode2* LinkedList::makeEmptyLinkedList2() {
        LinkedListNode2 *lp = (LinkedListNode2 *) malloc(sizeof(LinkedListNode2));
        lp->next = ( LinkedListNode2 *) 0;
        lp->prev = ( LinkedListNode2 *) 0;
        lp->payP = (Payload2 *) 0;

        return lp;
    }

    void LinkedList:: savePayload(LinkedListNode *lp, Payload *mp) {
        //if the list is empty, then make payP be mp
        //else traverse the list,
        //make a new list element
        //put mp in that
        //attach the new list element to the existing list
        if (isEmpty(lp)) {
            lp->payP = mp;
        } else {
            LinkedListNode *temp = lp;
            while (temp->next) {
                temp = (LinkedListNode *) temp->next;
            }
            //now temp points to the last element

            //make a new element, attach mp to it, wire up the new element
            LinkedListNode *newList = makeEmptyLinkedList();
            newList->payP = mp;
            temp->next = (LinkedListNode *) newList;
            newList->prev = (LinkedListNode *) temp;
        }
    }

    void LinkedList:: savePayload2(LinkedListNode2 *lp, Payload2 *mp) {
        //if the list is empty, then make payP be mp
        //else traverse the list,
        //make a new list element
        //put mp in that
        //attach the new list element to the existing list
        if (isEmpty2(lp)) {
            lp->payP = mp;
        } else {
            LinkedListNode2 *temp = lp;
            while (temp->next) {
                temp = (LinkedListNode2 *) temp->next;
            }
            //now temp points to the last element

            //make a new element, attach mp to it, wire up the new element
            LinkedListNode2 *newList = makeEmptyLinkedList2();
            newList->payP = mp;
            temp->next = (LinkedListNode2 *) newList;
            newList->prev = (LinkedListNode2 *) temp;
        }
    }

    LinkedList::Payload* LinkedList::dequeueLIFO(LinkedListNode *lp) {
        Payload *payP = (Payload *) 0;
        if (isEmpty(lp)) {
            puts("Trying to dequeue from empty.");
        } else {

            LinkedListNode *temp = lp;
            while (temp->next) {
                temp = (LinkedListNode *) temp->next;
            }
            //now temp points to the last element


            payP = temp->payP;
            temp->payP = (Payload *) 0;
            printf("Room being retured is %d\n", payP->roomNumber);
            fflush(stdout);
            //remove the last, now empty, element
            if (temp->prev) {
                temp = (LinkedListNode *) temp->prev;
                //free(temp->next);
                printf("end of queue is room %d\n", temp->payP->roomNumber);
                fflush(stdout);
                temp->next = (LinkedListNode *) 0;
            } else {
                puts("Queue is now empty");
            }
            puts("returning from dequeue");
            fflush(stdout);
        }

        return payP;
    }

   LinkedList::backFromDQFIFO* LinkedList::dequeueFIFO(LinkedListNode *lp) {
        backFromDQFIFO *fp = (backFromDQFIFO *) malloc(sizeof(backFromDQFIFO));
        if (lp->next == (LinkedListNode *) 0) {
            //list of length 1 or 0
            fp->newQHead = lp;
        } else {
            fp->newQHead = (LinkedListNode *) lp->next;
        }
        fp->mp = lp->payP;//all return values are set
        if (lp->next != (LinkedListNode *) 0) {
            //length list is >1
            free(lp);
        }

        return fp;
    }

    void LinkedList::printHistory(LinkedListNode2 *hp) {
        ofstream fileOut;
        fileOut.open("../output.txt");
        puts("Printing history");
        if (hp->payP == (Payload2 *) 0) {
            fileOut<<("Empty list\n");
        } else {
            //traverse the list, printing as we go
            float treasureSubtotal = 0.0;
            int room = -1;
            LinkedListNode2 *temp = hp;
            while (temp->next) {
                room = temp->payP->roomNumber;
                treasureSubtotal += temp->payP->treasure;
                fileOut<<room << " "<< treasureSubtotal<<endl;
                temp = (LinkedListNode2 *) temp->next;

            }
            room = temp->payP->roomNumber;
            treasureSubtotal += temp->payP->treasure;
            fileOut<<room << " "<< treasureSubtotal<<endl;
        }
        fileOut.close();
    }

    LinkedList::LinkedListNode * LinkedList::removeFromList(LinkedListNode *hP, Payload *pP) {
        LinkedListNode *retHead = hP;//only changes if first element gets removed
        //find the payload
        //use the structure of a list, namely, list is empty or element followed by list
        if (isEmpty(hP)) {
            //nothing to do
        } else {
            //puts("list is not empty");fflush(stdout);
            LinkedListNode *altHead = (LinkedListNode *) hP->next;
            //find the item, if it is there
            LinkedListNode *temp = hP;
            bool done = false;
            while ((!done) && temp->next) {
                //are we there yet?
                if (temp->payP == pP) {
                    done = true;
                    //puts("found it 1");fflush(stdout);
                } else {
                    temp = (LinkedListNode *) temp->next;
                }
            }
            //either we are pointing to the correct element, or we are at the end, or both
            if ((temp->payP) == pP) {
                //puts("found it 2");fflush(stdout);
                //found it, remove it
                //are we at the beginning?
                if (temp == hP) {  //found it at the first element
                    //puts("found it at first element");fflush(stdout);
                    //is the list of length 1?
                    if (!(temp->next)) {//if there is no next
                        //remove payload, return empty list
                        hP->payP = (Payload *) 0;
                    } else //not of length 1
                    { //not freeing the Payload, but freeing the first list element
                        //puts("found it at first element of list with length > 1");fflush(stdout);
                        //free(hP);
                        retHead = altHead;
                    }
                } else //not found at first location in list
                {
                    //puts("found it not at first element");fflush(stdout);
                    //save the linkages
                    //found element has a next
                    //found element has a prev
                    //participant before has a next
                    //participant after has a prev
                    LinkedListNode *prevPart = (LinkedListNode *) temp->prev;//non-zero because not at first element
                    LinkedListNode *nextPart = (LinkedListNode *) temp->next;//could be zero, if found at last element
                    prevPart->next = (LinkedListNode *) nextPart;//RHS is 0 if at end
                    //puts("after setting the next of the previous");fflush(stdout);
                    // printf("Next is %p, %d\n", nextPart, (bool)nextPart);fflush(stdout);
                    if ((bool) nextPart)//don't need guarded block if element found at end of list
                    {
                        //puts("before setting the previous of the next");fflush(stdout);
                        nextPart->prev = (LinkedListNode *) prevPart;

                    }
                    //puts("after handling the  previous of the next");fflush(stdout);
                }//end of not found at first location
            }//end of found it
            else {
                //didn't find it
                //puts("did not find it");fflush(stdout);
                //nothing to do
            }//end did not find it
        }
        //printf("Returning %p\n", retHead); fflush(stdout);
        return retHead;
    }