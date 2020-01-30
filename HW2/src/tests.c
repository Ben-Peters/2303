/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "display.h"

bool tests()
{
	bool answer = false;
	bool ok1 =  testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testSomethingElse();
	bool ok4 = testRemoveFromList();
	answer = ok1 && ok2 && ok3 && ok4;
	return answer;
}

bool testReadFile()
{
	bool ok = false;
	puts("starting testReadFile");fflush(stdout);
	//what are the criteria for success for
	//test case 1:
	//test case 2:

    if(ok)
    {
    	puts("test read file passed.");
    }
    else
    {
    	puts("test read file did not pass.");
    }
	return ok;
}

bool testGotAdjacencyMatrix()
{
	bool ans = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ans;
}

bool testSomethingElse()
{
	bool ans = true;
	puts("Testing the initSpace:");
    int* theSpaceP = (int*) malloc(20*20*sizeof(int));
    bool okInit = initSpace(theSpaceP, 20);
    print2DArray(theSpaceP, 20);
    for(int row = 0; row < 20; row++){
        for(int col = 0; col < 20; col++){
            if(*(theSpaceP+row*20 + col) != 0){
                ans = false;
                puts("Not all the values were 0");
            }
        }
    }
    if(ans){
        puts("initSpace tests passed!");
    }
	return ans;
}
bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
