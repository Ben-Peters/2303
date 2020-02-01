

#include "display.h"
#include "marker.h"
#include <stdio.h>

void print2DArray(int* start, int numRows){
    for(int i = 0; i < numRows;i++){
    	printf("─┼");
    }
    puts("");

    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numRows; col++){
            printf("%d│",*(start+row*numRows + col));
        }
	puts("");
        for(int i = 0; i < numRows;i++){
            printf("─┼");
        }
        puts("");
    }
}

void print2DArrayWithMarker(int* start, int numRows, Marker* mark) {
    for(int i = 0; i < numRows;i++){
    	printf("─┼");
    }
    puts("");

    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numRows; col++){
	    if(col == mark->col && row == mark->row) {
		printf("X│");
	    } else {
                printf(" │");
	    }
        }
	puts("");
        for(int i = 0; i < numRows;i++){
            printf("─┼");
        }
        puts("");
    }
}
