

#include "display.h"
#include "marker.h"
#include "LinkedList.h"
#include <stdio.h>

void print2DArray(int* start, int numRows){
    for(int i = 0; i < numRows;i++){
    	printf("─┼");
    }
    puts("");

    for(int row = 0; row < numRows; row++){
        for(int col = numRows - 1; col >= 0; col--){
            printf("%d│",*(start+row*numRows + col));
        }
	puts("");
        for(int i = 0; i < numRows;i++){
            printf("─┼");
        }
        puts("");
    }
}

void print2DArrayWithoutZero(int* start, int numRows) {
    for(int i = 0; i < numRows;i++){
    	printf("──┼");
    }
    puts("");
    for(int row = 0; row < numRows; row++){
        for(int col = numRows - 1; col >= 0; col--){
	    if( *(start+row*numRows+col) == 0) {
		printf("  │");
	    } else {
		if(*(start+row*numRows + col) < 10){printf(" ");}
            	printf("%d│",*(start+row*numRows + col) );
	    }
        }
	puts("");
        for(int i = 0; i < numRows;i++){
            printf("──┼");
        }
        puts("");
    }
}

int traverseAndPrint(LLNode* ll, bool print) {
	if(print) puts("BEGIN list traversal & path history >>>");
	int count = 0;
	if(ll->payP == (Payload*)0) {
		if(print) {puts("Empty list.");}
	}else{
		LLNode* temp = ll;
		while(temp) {
			count++;
			if(print) {
				printf("Node #%d", temp->payP->index);
				printf(" @ %d,", temp->payP->row);
				printf(" %d\n", temp->payP->col);
			}
			temp = (LLNode*)temp->next;
		}
	}
	if(print) puts("<<< END traversal");
	return count;
}
