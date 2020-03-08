//
// Created by Tom Nurse on 3/7/20.
//

#include "Board.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battleship.h"
#include "Sub.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

Board::Board() {

}

Board::~Board() {

}

Ship::Ship() {

}

Ship::~Ship() {

}

Ship::Ship(int size, char id, bool sunk) {
    this->size = size;
    this->id = id;
    this->sunk = sunk;
}

Board::Board(int size, char name[]) {
    this->size = size;
    for (int k = 0; k < (sizeof(name)/sizeof(char)); k++){
        this->playerName[k] = name[k];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->cells[i][j] = '~';
        }
    }

    for (int i = 0; i < 4; i++){
        this->ships[i] = new Ship();
    }
}

int Board::qtyShipsLeft() {
    int count = 5;
    for (int i = 0; i < 5; i++){
        if (ships[i]->sunk){
            count--;
        }
    }
    return count;
}

char Board::getCellValue(int row, int col) {
    return cells[row][col];
}

void Board::printBoard(bool withShips) {
    std::cout << "  ";
    for (int a = 0; a < size; a++){
        std::cout << a;
        std::cout << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << i << " ";

        for (int j = 0; j < size; j++) {
            char id = cells[i][j];
            if (!withShips && (id == '~' || id == '*' || id == 'm')) {
                std::cout << cells[i][j] << " ";
            }else if (!withShips){
                std::cout << '~' << " ";
            }else{
                std::cout << cells[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::addShip(Ship* ship, int row, int col, char direction) {
    for (int i = 0; i < ship->size; i++){
        int currRow = row;
        int currCol = col;
        switch (direction){
            case 'n': // North
                currRow -= i;
            break;

            case 'e': // East
                currCol += i;
            break;

            case 's': // South
                currRow += i;
            break;

            case 'w': // West
                currCol -= i;
            break;

            default:
                puts("Error adding ship");
        }
        cells[currRow][currCol] = ship->id;
    }
}

void Board::manuallyAddShip(Ship* ship, int index, int row, int col, char direction){
    ships[index] = ship;
    addShip(ship, row, col, direction);
}

void Board::placeShipsRandom() {
    std::cout << "Loading " << this->playerName << " board..." << std::endl;
    Carrier* carrier = new Carrier();
    Cruiser* cruiser = new Cruiser();
    Destroyer* destroyer = new Destroyer();
    Battleship* battleship = new Battleship();
    Sub* sub = new Sub();
    ships[0] = carrier;
    ships[1] = battleship;
    ships[2] = cruiser;
    ships[3] = sub;
    ships[4] = destroyer;
    for (int i = 0; i < 5; i++) {
        bool valid = false;
        int row = 0;
        int col = 0;
        char dir;
        while (valid == false) {
            srand(time(NULL));
            row = rand() % (size-1);
            srand(time(NULL));
            col = rand() % (size-1);
            int direction = rand() % 3;
            switch (direction){
                case 0:
                    dir = 'n';
                    break;

                case 1:
                    dir = 'e';
                    break;

                case 2:
                    dir = 's';
                    break;

                case 3:
                    dir = 'w';
                    break;

                default:
                    puts("Failed to determined acceptable direction");
            }
            if (isValidLocation(row, col, ships[i]->size, dir)){
                valid = true;
            }
        }
        addShip(ships[i], row, col, dir);
    }
}

bool Board::isValidLocation(int row, int col, int length, char direction) {
    bool isValid = true;

    for (int i = 0; i < length; i++) {
        if (direction == 'w') {
            if (cells[row][col - i] != '~' || (col - i) < 0) {
                isValid = false;
            }
        } else if (direction == 'e'){
            if (cells[row][col + i] != '~' || (col + i) >= size){
                isValid = false;
            }
        } else if (direction == 's'){
            if (cells[row + i][col] != '~' || (row + i) >= size) {
                isValid = false;
            }
        } else {
            if (cells[row - i][col] != '~' || (row - i) < 0){
                isValid = false;
            }
        }
    }
    return isValid;
}

void Board::updateBoard(int row, int col) {
    if (cells[row][col] != '~' && cells[row][col] != 'm'){
        cells[row][col] = '*';
        //puts("Hit");
    }else if (cells[row][col] == 'm'){
        // Maybe tell them to select something they haven't tried
        //puts("Miss");
    }else{
        cells[row][col] = 'm';
        //puts("Miss");
    }
}

bool Board::checkBounds(int row, int col) {
    if (row < 0 || row > (size-1)){
        return false;
    }else if (col < 0 || col > (size-1)){
        return false;
    }else{
        return true;
    }
}

bool Board::didSink() {
    int carrier = 0;
    int destroyer = 0;
    int cruiser = 0;
    int battleship = 0;
    int sub = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            char id = cells[i][j];
            if (id == 'c'){
                carrier++;
            }
            if (id == 'd'){
                destroyer++;
            }
            if (id == 'b'){
                battleship++;
            }
            if (id == 's'){
                sub++;
            }
            if (id == 'u'){
                cruiser++;
            }
        }
    }
    int totals[] = {carrier, battleship, cruiser, sub, destroyer};
    char shipNames[5][11] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
    for (int k = 0; k < (sizeof(totals)/sizeof(int)); k++){
        if (totals[k] == 0){
            if (!ships[k]->sunk){
                std::cout << playerName << " " << shipNames[k] << " has been sunk!" << std::endl;
                ships[k]->sunk = true;
                return true;
            }
        }
    }
    return false;
}