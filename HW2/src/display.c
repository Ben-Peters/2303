

#include "display.h"
#include "marker.h"
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
    	printf("─┼");
    }
    puts("");
    for(int row = 0; row < numRows; row++){
        for(int col = numRows - 1; col >= 0; col--){
	    if( *(start+row*numRows+col) == 0) {
		printf(" │");
	    } else {
            	printf("%d│",*(start+row*numRows + col));
	    }
        }
	puts("");
        for(int i = 0; i < numRows;i++){
            printf("─┼");
        }
        puts("");
    }
    puts("");
}
