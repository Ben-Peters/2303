//
// Created by Tom on 3/7/20.
//

#include "Tests.h"
#include "Production.h"
#include "Board.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Destroyer.h"
#include "Sub.h"
#include <stdio.h>

using namespace std;

Tests::Tests() {

}

Tests::~Tests() {

}

bool Tests::tests() {
    bool answer = true;
    answer &= testInitBoard();
    answer &= testGetTarget();
    answer &= testBoundsCheck();
    answer &= testCheckShot();
    answer &= testDidSinkShip();
    answer &= testGetPosition();
    answer &= testIsValidLocation();
    answer &= testNewShip();
    answer &= testPrintBoard();
    answer &= testStringToLocation();
    answer &= testWinner();
    answer &= testUpdateBoard();
    return  answer;
}

bool Tests::testInitBoard() {
    bool ok = true;
    const int rows = 8;
    char cells[rows][rows];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            cells[i][j] = '~';
        }
    }
    Board* board = new Board(rows);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            int k = board->getCellValue(i, j);
            if (k != cells[i][j]){
                ok = false;
                puts("Fail: Board was not initialized correctly");
            }
        }
    }
    if (ok){
        puts("Pass: Board was initialized correctly");
    }
    return ok;
}

bool Tests::testPrintBoard() {
    bool ok = true;
    Board *board = new Board(8);
    board->printBoard(false);

    Board *board2 = new Board(10);
    board2->printBoard(false);
    puts("Pass: Board was printed properly");
    return ok;
}

bool Tests::testNewShip() {
    bool case1 = true;
    bool case2 = true;
    bool case3 = true;
    bool case4 = true;
    int rows = 10;
    Battleship* ship1 = new Battleship();
    Sub* ship2 = new Sub();
    Destroyer* ship3 = new Destroyer();
    Carrier* ship4 = new Carrier();
    Board* board = new Board(rows);
    Board* board2 = new Board(rows);
    Board* board3 = new Board(rows);
    Board* board4 = new Board(rows);
    board->addShip(ship1, 5, 7, 'w');
    board2->addShip(ship2, 2, 7, 'n');
    board3->addShip(ship3, 2, 2, 's');
    board4->addShip(ship4, 7, 5, 'e');
    char answer[rows][rows];
    char answer2[rows][rows];
    char answer3[rows][rows];
    char answer4[rows][rows];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            answer[i][j] = '~';
            answer2[i][j] = '~';
            answer3[i][j] = '~';
            answer4[i][j] = '~';
        }
    }
    answer[5][7] = 'b';
    answer[5][6] = 'b';
    answer[5][5] = 'b';
    answer[5][4] = 'b';

    answer2[2][7] = 's';
    answer2[1][7] = 's';
    answer2[0][7] = 's';

    answer3[2][2] = 'd';
    answer3[3][2] = 'd';
    answer3[4][2] = 'd';

    answer4[7][5] = 'c';
    answer4[7][6] = 'c';
    answer4[7][7] = 'c';
    answer4[7][8] = 'c';
    answer4[7][9] = 'c';

    for (int k = 0; k < rows; k++){
        for (int l = 0; l < rows; l++){
            if (answer[k][l] != board->getCellValue(k, l)){
                case1 = false;
                puts("Fail: New battleship was not created or added to the board properly");
            }
            if (answer2[k][l] != board2->getCellValue(k, l)){
                case2 = false;
                puts("Fail: New submarine was not created or added to the board properly");
            }
            if (answer3[k][l] != board3->getCellValue(k, l)){
                case3 = false;
                puts("Fail: New destroyer was not created or added to the board properly");
            }
            if (answer4[k][l] != board4->getCellValue(k, l)){
                case4 = false;
                puts("Fail: New carrier was not created or added to the board properly");
            }
        }
    }
    if (case1 && case2 && case3 && case4){
        puts("Pass: All new ships were added to the board successfully");
    }else{
        board->printBoard(true);
        board2->printBoard(true);
        board3->printBoard(true);
        board4->printBoard(true);
    }
    return case1 && case2 && case3 && case4;
}

bool Tests::testUpdateBoard() {
    bool ok = false;
    Board* board = new Board(10);

    puts("Fail: Board was not updated properly");
    return ok;
}

bool Tests::testBoundsCheck() {
    bool ok = false;
    puts("Fail: Condition found over board bounds");
    return ok;
}

bool Tests::testDidSinkShip() {
    bool ok = false;
    puts("Fail: Unable to successfully determine if ship was sunk");
    return ok;
}

bool Tests::testIsValidLocation() {
    Board* board = new Board(10);
    bool case1 = board->isValidLocation(3, 5, 3, 'e');
    if (!case1){
        puts("Fail: Incorrect evaluation of valid location");
    }
    Battleship* ship = new Battleship();
    board->addShip(ship, 5, 2, 's');
    bool case2 = board->isValidLocation(7, 6, 5, 'w');
    if (case2){
        puts("Fail: Unable to identify invalid location - ship already present");
    }
    bool case3 = board->isValidLocation(8, 8, 3, 'e');
    if (case3){
        puts("Fail: Incorrect evaluation of invalid location - beyond board bounds");
    }
    if (case1 && !case2 && !case3){
        puts("Pass: Successfully determines valid locations for ships");
    }
    return case1 && !case2 && !case3;
}

bool Tests::testStringToLocation() {
    bool ok = false;
    puts("Fail: String was not converted to location properly");
    return ok;
}

bool Tests::testWinner() {
    bool ok = false;
    puts("Fail: Unable to determine correct winner");
    return ok;
}

bool Tests::testGetTarget() {
    bool ok = false;
    puts("Fail: Returns incorrect target");
    return ok;
}

bool Tests::testGetPosition() {
    bool ok = false;
    puts("Fail: Returns incorrect position");
    return ok;
}

bool Tests::testCheckShot() {
    bool ok = false;
    puts("Fail: Unable to successfully check shot");
    return ok;
}

