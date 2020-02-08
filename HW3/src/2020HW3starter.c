/*
 ============================================================================
 Name        : 2020HW3starter.c
 Author      : Ben Peters, Tom Nurse, Alexander Hayden
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
	puts("!!!Let's do  HW3!!!"); /* prints !!!Hello World!!! */
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
