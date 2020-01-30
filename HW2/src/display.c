

#include "display.h"


void print2DArray(int* start, int numRows){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numRows; col++){
            printf("%d|",*(start+row*numRows + col));
        }
        for(int i = 0; i < numRows;i++){
            printf("-");
        }
        puts("");
    }
}

