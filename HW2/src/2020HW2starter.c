/*
 ============================================================================
 Name        : HW2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Homework #2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tests.h"
#include "production.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW2  !!!");
	srand(time(NULL));//initialize rng
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
