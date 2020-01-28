/*
 * LinkedList.c
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */


#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

bool isEmpty(LLNode* lp)
{
	bool ans = false;
	if(lp->payP == (Payload*)0)
	{
		ans = true;
	}
	return ans;
}
bool isEmpty2(LLNode2* lp)
{
	bool ans = false;
	if(lp->payP == (Payload2*)0)
	{
		ans = true;
	}
	return ans;
}

LLNode* makeEmptyLinkedList()
{
	LLNode* lp = (LLNode*) malloc(sizeof(LLNode));
	lp->next = (struct LLNode*)0;
	lp->prev = (struct LLNode*)0;
	lp->payP = (Payload*)0;

	return lp;
}
LLNode2* makeEmptyLinkedList2()
{
	LLNode2* lp = (LLNode2*) malloc(sizeof(LLNode2));
	lp->next = (struct LLNode2*)0;
	lp->prev = (struct LLNode2*)0;
	lp->payP = (Payload2*)0;

	return lp;
}
void savePayload(LLNode* lp, Payload* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty(lp))
	{
		lp->payP = mp;
	}
	else
	{
		LLNode* temp = lp;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode* newList = makeEmptyLinkedList();
		newList->payP = mp;
		temp->next = (struct LLNode*)newList;
		newList->prev = (struct LLNode*) temp;
	}
}
void savePayload2(LLNode2* lp, Payload2* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty2(lp))
	{
		lp->payP = mp;
	}
	else
	{
		LLNode2* temp = lp;
		while(temp->next)
		{
			temp=(LLNode2*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode2* newList = makeEmptyLinkedList2();
		newList->payP = mp;
		temp->next = (struct LLNode2*) newList;
		newList->prev = (struct LLNode2*) temp;
	}
}

Payload* dequeueLIFO(LLNode* lp)
{
	Payload* payP = (Payload*)0;
	if(isEmpty(lp))
	{
		puts("Trying to dequeue from empty.");
	}
	else
	{

		LLNode* temp = lp;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element


		payP = temp->payP;
		temp->payP = (Payload*)0;

		//remove the last, now empty, element
		if(temp->prev)
		{
			temp=(LLNode*)temp->prev;
			//free(temp->next);

			temp->next = (struct LLNode*)0;
		}
		else
		{
			puts("Queue is now empty");
		}
		puts("returning from dequeue");fflush(stdout);
	}

	return payP;
}

backFromDQFIFO* dequeueFIFO(LLNode* lp)
{
	backFromDQFIFO* fp = (backFromDQFIFO*) malloc(sizeof(backFromDQFIFO));
	if(lp->next == (struct LLNode*)0)
	{
		//list of length 1 or 0
		fp->newQHead= lp;
	}
	else
	{
		fp->newQHead= (LLNode*) lp->next;
	}
	fp->mp= lp->payP;//all return values are set
	if(lp->next != (struct LLNode*)0)
	{
		//length list is >1
		free(lp);
	}

	return fp;
}
void printHistory(LLNode2* hp)
{
    puts("Printing history");
    if(hp->payP ==(Payload2*)0)
    {
         puts("Empty list");
    }
    else
    {
	    //traverse the list, printing as we go
        float treasureSubtotal = 0.0;
        int room = -1;
        LLNode2* temp = hp;
        while(temp->next)
        {
            room =temp->payP->roomNumber;
            treasureSubtotal+= temp->payP->treasure;
            printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
            temp=(LLNode2*)temp->next;

        }
        room =temp->payP->roomNumber;
        treasureSubtotal+= temp->payP->treasure;
        printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
    }
}
LLNode* removeFromList(LLNode* hP, Payload* pP)
{
	LLNode* retHead = hP;//only changes if first element gets removed
	//find the payload
	//use the structure of a list, namely, list is empty or element followed by list
	if(isEmpty(hP))
	{
		//nothing to do
	}
	else
	{
		//puts("list is not empty");fflush(stdout);
		LLNode* altHead = (LLNode*)hP->next;
		//find the item, if it is there
		LLNode* temp = hP;
		bool done = false;
		while((!done) && temp->next)
		{
			//are we there yet?
			if(temp->payP == pP)
			{
				done=true;
				//puts("found it 1");fflush(stdout);
			}
			else
			{
				temp=(LLNode*)temp->next;
			}
		}
		//either we are pointing to the correct element, or we are at the end, or both
		if((temp->payP) == pP)
		{
			//puts("found it 2");fflush(stdout);
			//found it, remove it
			//are we at the beginning?
			if(temp == hP)
			{  //found it at the first element
				//puts("found it at first element");fflush(stdout);
				//is the list of length 1?
				if(!(temp->next))
				{//if there is no next
					//remove payload, return empty list
					hP->payP = (Payload*)0;
				}
				else //not of length 1
				{ //not freeing the Payload, but freeing the first list element
					//puts("found it at first element of list with length > 1");fflush(stdout);
					//free(hP);
					retHead = altHead;
				}
			}
			else //not found at first location in list
			{
				//puts("found it not at first element");fflush(stdout);
				//save the linkages
				//found element has a next
				//found element has a prev
				//participant before has a next
				//participant after has a prev
				LLNode* prevPart = (LLNode*) temp->prev;//non-zero because not at first element
				LLNode* nextPart = (LLNode*) temp->next;//could be zero, if found at last element
				prevPart->next = (struct LLNode*) nextPart;//RHS is 0 if at end
				//puts("after setting the next of the previous");fflush(stdout);
               // printf("Next is %p, %d\n", nextPart, (bool)nextPart);fflush(stdout);
				if((bool)nextPart)//don't need guarded block if element found at end of list
				{
					//puts("before setting the previous of the next");fflush(stdout);
					nextPart->prev = (struct LLNode*) prevPart;

				}
				//puts("after handling the  previous of the next");fflush(stdout);
			}//end of not found at first location
		}//end of found it
		else
		{
			//didn't find it
			//puts("did not find it");fflush(stdout);
			//nothing to do
		}//end did not find it
	}
	//printf("Returning %p\n", retHead); fflush(stdout);
	return retHead;
}
