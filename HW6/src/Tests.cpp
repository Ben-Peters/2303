//
// Created by Tom on 3/7/20.
//

#include "Tests.h"
#include "Production.h"
#include "Board.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Destroyer.h"
#include "Cruiser.h"
#include "Sub.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Tests::Tests() {

}

Tests::~Tests() {

}

bool Tests::tests() {
    bool answer = true;
    answer &= testInitBoard();
    answer &= testBoundsCheck();
    answer &= testDidSinkShip();
    answer &= testIsValidLocation();
    answer &= testNewShip();
    answer &= testPrintBoard();
    answer &= testWinner();
    answer &= testUpdateBoard();
    if (answer){
        puts("All tests passed");
    }
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
    Board* board = new Board(rows, "TEST");
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
    Board *board = new Board(8, "TEST");
    board->printBoard(false);

    Board *board2 = new Board(10, "TEST");
    board2->printBoard(false);
    puts("Pass: Board was printed properly");
    return ok;
}

bool Tests::testNewShip() {
    bool case1 = true;
    bool case2 = true;
    bool case3 = true;
    bool case4 = true;
    bool case5 = true;
    int rows = 10;
    Battleship* ship1 = new Battleship();
    Sub* ship2 = new Sub();
    Destroyer* ship3 = new Destroyer();
    Carrier* ship4 = new Carrier();
    Cruiser* ship5 = new Cruiser();
    Board* board = new Board(rows, "TEST");
    Board* board2 = new Board(rows, "TEST");
    Board* board3 = new Board(rows, "TEST");
    Board* board4 = new Board(rows, "TEST");
    Board* board5 = new Board(rows, "TEST");
    board->addShip(ship1, 5, 7, 'w');
    board2->addShip(ship2, 2, 7, 'n');
    board3->addShip(ship3, 2, 2, 's');
    board4->addShip(ship4, 7, 5, 'e');
    board5->addShip(ship5, 1, 2, 'e');
    char answer[rows][rows];
    char answer2[rows][rows];
    char answer3[rows][rows];
    char answer4[rows][rows];
    char answer5[rows][rows];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            answer[i][j] = '~';
            answer2[i][j] = '~';
            answer3[i][j] = '~';
            answer4[i][j] = '~';
            answer5[i][j] = '~';
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

    answer4[7][5] = 'c';
    answer4[7][6] = 'c';
    answer4[7][7] = 'c';
    answer4[7][8] = 'c';
    answer4[7][9] = 'c';

    answer5[1][2] = 'u';
    answer5[1][3] = 'u';
    answer5[1][4] = 'u';

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
            if (answer5[k][l] != board5->getCellValue(k, l)){
                case5 = false;
                puts("Fail: New cruiser was not created or added to the board properly");
            }
        }
    }
    if (case1 && case2 && case3 && case4 && case5){
        puts("Pass: All new ships were added to the board successfully");
    }else{
        board->printBoard(true);
        board2->printBoard(true);
        board3->printBoard(true);
        board4->printBoard(true);
        board5->printBoard(true);
    }
    return case1 && case2 && case3 && case4 && case5;
}

bool Tests::testUpdateBoard() {
    bool case1 = true;
    bool case2 = true;
    int rows = 10;
    Board* board = new Board(rows, "TEST");
    Board* board2 = new Board(rows, "TEST");
    char answer[rows][rows];
    char answer2[rows][rows];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            answer[i][j] = '~';
            answer2[i][j] = '~';
        }
    }
    answer[2][3] = 'm';
    answer2[2][2] = 's';
    answer2[2][3] = '*';
    answer2[2][4] = 's';
    board->updateBoard(2, 3);
    Sub* sub = new Sub();
    board2->addShip(sub, 2, 2, 'e');
    board2->updateBoard(2, 3);
    for (int a = 0; a < rows; a++){
        for (int b = 0; b < rows; b++){
            if (answer[a][b] != board->getCellValue(a, b)){
                case1 = false;
                puts("Fail: Board was not updated properly - incorrect symbol for 'miss'");
            }
            if (answer2[a][b] != board2->getCellValue(a, b)){
                case2 = false;
                puts("Fail: Board was not updated properly - incorrect symbol for 'hit'");
            }
        }
    }
    if (case1 && case2){
        puts("Pass: Board was updated successfully");
    }else{
        board2->printBoard(true);
    }
    return case1 && case2;
}

bool Tests::testBoundsCheck() {
    Board* board = new Board(10, "TEST");
    bool case1 = board->checkBounds(0, 0);
    bool case2 = board->checkBounds(0, 10);
    bool case3 = board->checkBounds(10, 5);
    bool case4 = board->checkBounds(5, 9);
    if (!case1 || case2 || case3 || !case4){
        puts("Fail: One or more out-of-bounds checks failed");
    }else{
        puts("Pass: Out-of-bounds check works");
    }
    return case1 && !case2 && !case3 && case4;
}

bool Tests::testDidSinkShip() {
    Board* board = new Board(10, "TEST");
    Sub* sub = new Sub();
    Destroyer* destroyer = new Destroyer();
    Battleship* battleship = new Battleship();
    Carrier* carrier = new Carrier();
    Cruiser* cruiser = new Cruiser();
    board->manuallyAddShip(sub, 0, 2, 2, 'e');
    board->manuallyAddShip(destroyer, 1, 6, 4, 'e');
    board->manuallyAddShip(battleship, 2, 4, 4, 's');
    board->manuallyAddShip(carrier, 3, 3, 2, 's');
    board->manuallyAddShip(cruiser, 4, 4, 5, 'e');
    board->updateBoard(2,3);
    board->updateBoard(2,4);
    board->updateBoard(2,5);
    bool case1 = board->didSink();
    board->updateBoard(2, 2);
    bool case2 = board->didSink();
    if (case1){
        puts("Fail: Returned true; ship has not been sunk yet");
    }else if (!case2){
        puts("Fail: Returned false; ship has sunk");
    }else{
        puts("Pass: Correctly identifies when a ship has sunk");
    }
    return !case1 && case2;
}

bool Tests::testIsValidLocation() {
    Board* board = new Board(10, "TEST");
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

bool Tests::testWinner() {
    bool ok = false;
    Board* user = new Board(5, "TEST");
    Board* cpu = new Board(5, "TEST");
    Sub* sub = new Sub();
    Carrier* carrier = new Carrier();
    user->manuallyAddShip(sub, 0, 2, 2, 'e');
    user->manuallyAddShip(sub, 1, 3, 2, 'e');
    user->manuallyAddShip(sub, 2, 4, 2, 'e');
    user->manuallyAddShip(sub, 3, 0, 2, 'e');
    user->manuallyAddShip(sub, 4, 1, 2, 'e');
    cpu->manuallyAddShip(sub, 0, 2, 2, 'e');
    cpu->manuallyAddShip(sub, 1, 3, 2, 'e');
    cpu->manuallyAddShip(sub, 2, 4, 2, 'e');
    cpu->manuallyAddShip(sub, 3, 0, 2, 'e');
    cpu->manuallyAddShip(sub, 4, 1, 2, 'e');
    int result1 = Production::checkForWinner(user, cpu);
    user->updateBoard(2, 2);
    user->updateBoard(2, 3);
    user->updateBoard(2, 4);
    user->updateBoard(3, 2);
    user->updateBoard(3, 3);
    user->updateBoard(3, 4);
    user->updateBoard(4, 2);
    user->updateBoard(4, 3);
    user->updateBoard(4, 4);
    user->updateBoard(0, 2);
    user->updateBoard(0, 3);
    user->updateBoard(0, 4);
    user->didSink();
    int result2 = Production::checkForWinner(user, cpu);
    user->manuallyAddShip(carrier, 1, 4, 6, 'w');
    cpu->updateBoard(2, 2);
    cpu->updateBoard(2, 3);
    cpu->updateBoard(2, 4);
    cpu->updateBoard(3, 2);
    cpu->updateBoard(3, 3);
    cpu->updateBoard(3, 4);
    cpu->updateBoard(4, 2);
    cpu->updateBoard(4, 3);
    cpu->updateBoard(4, 4);
    cpu->updateBoard(0, 2);
    cpu->updateBoard(0, 3);
    cpu->updateBoard(0, 4);
    cpu->didSink();
    int result3 = Production::checkForWinner(user, cpu);
    if (result1 == 0 && result2 == 2 && result3 == 1){
        ok = true;
        puts("Pass: Successfully determined correct winner");
    }else{
        puts("Fail: Unable to determine correct winner");
    }
    return ok;
}