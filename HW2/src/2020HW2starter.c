/*
 ============================================================================
 Name        : HW2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW2  !!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("About to run production.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");

	}
	return EXIT_SUCCESS;
}
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
