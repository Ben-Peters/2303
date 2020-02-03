/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "display.h"
#include "marker.h"

bool tests()
{
	puts("----- Tests -----");
	bool answer = false;
	bool ok1 = true;// testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testSomethingElse();
	bool ok4 = testRemoveFromList();
    bool ok5 = testForInvalidCoordinates();
	bool ok6 = testUpdateSpace();
	bool ok7 = testUpdateSpaceAtCoordinates();
	bool ok8 = testUpdateSpaceWithIndex();
	bool ok9 = testPlaceMarker();
	bool ok10 = testForAdjacentMarker();
	bool ok11 = testMarkerIndex();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11;

	ok1 = testDisplayTraceback();

	answer = answer && ok1;

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
    } else {
    	print2DArray(theSpaceP, 20);
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

bool testForInvalidCoordinates(){
    bool ok = true;
    // Check multiple instances
    for (int i = 0; i < 500; i++) {
        int *coordinates = getRandCoordinates();
        int row = *coordinates;
        int col = *(coordinates + 1);
        if (row >= 20 || col >= 20 || row < 0 || col < 0) {
            ok = false;
        }
    }
    if (ok){
        puts("Pass: All coordinates were within bounds");
    }else{
        puts("Fail: Invalid coordinates were generated");
    }
    return ok;
}

bool testUpdateSpace(){
    bool ok = false;
    int* space = (int*) malloc(sizeof(int)*20*20);
    initSpace(space, 20);
    updateSpace(space, 20, 1, 1, 1);
    int count = 0;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            int val = *(space+row*20+col);
            if (val != 0){
                count++;
            }
        }
    }
    if (count == 1){
        puts("Pass: Updated space successfully");
    }else if (count == 0){
        puts("Failed to update space");
    }else{
        puts("Fail: Multiple locations were updated");
    }
    return count == 1;
}

bool testUpdateSpaceAtCoordinates(){
    bool ok = false;
    int* space = (int*) malloc(sizeof(int)*20*20);
    initSpace(space, 20);
    int testRow = 4;
    int testCol = 2;
    updateSpace(space, 20, testRow, testCol, 1);
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            int val = *(space+row*20+col);
            if (val != 0){
                if (row == testRow && col == testCol){
                    ok = true;
                }
            }
        }
    }
    if (ok){
        puts("Pass: Updated space at correct coordinates");
    }else{
        puts("Failed to update space at correct coordinates");
    }
    return ok;
}

bool testUpdateSpaceWithIndex(){
    bool ok = false;
    int* space = (int*) malloc(sizeof(int)*20*20);
    initSpace(space, 20);
    int index = 5;
    updateSpace(space, 20, 1, 1, index);
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            int val = *(space+row*20+col);
            if (val == index){
                ok = true;
            }
        }
    }
    if (ok){
        puts("Pass: Updated space with correct index");
    }else{
        puts("Failed to update space with correct index");
    }
    return ok;
}

bool testPlaceMarker() {
	bool ok = true;
	Marker* p = placeMarker(3, 4);
	ok = ok && p->row == 3;
	ok = ok && p->col == 4;
	
	if(ok) {
		puts("Pass: Marker placed properly");
	} else {
		puts("Failed to place a marker");
	}

	return ok;
}

bool testDisplayTraceback() {
	bool ok = false;
	LLNode* ll = makeEmptyLinkedList();
	
	Marker* p = placeMarker(0, 0);
	p->index = 0;
	savePayload(ll, p);
	
	p = placeMarker(1, 1);
	p->index = 1;
	savePayload(ll, p);

	p = placeMarker(2, 2);
	p->index = 2;
	savePayload(ll, p);
	
	ok = traverseAndPrint(ll, false) == 3;
	
	if(ok) {
		puts("Pass: traversed properly");
	} else {
		puts("Failed to traverse");
	}
	return ok;

}

bool testForAdjacentMarker(){
    bool ok = true;
    for (int i = 0; i < 10; i++) { // Tests the function multiple times
        Marker *marker = placeMarker(5, 5);
        marker = makeAdjacentMarker(marker, 1);
        int row = marker->row;
        int col = marker->col;

        // Possible solutions
        if ((row == 4 || row == 5 || row == 6) && (col == 4 || col == 5 || col == 6)) {
            // Pass
        }else{
            ok = false;
        }
    }
    if (ok){
        puts("Pass: All markers were adjacent");
    }else{
        puts("Fail: One or more markers were not adjacent");
    }

    return ok;
}

bool testMarkerIndex(){
    bool ok = false;
    Marker* marker = placeMarker(5, 5);
    marker->index = 4;
    marker = makeAdjacentMarker(marker, marker->index + 1);

    if (marker->index == 5){
        ok = true;
    }

    if (ok){
        puts("Pass: Marker index verified");
    }else{
        puts("Failed to update index");
    }

    return false;
}