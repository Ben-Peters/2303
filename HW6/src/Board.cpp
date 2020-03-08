//
// Created by Tom Nurse on 3/7/20.
//

#include "Board.h"
#include "Carrier.h"
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

Ship::Ship(int size, char id) {
    this->size = size;
    this->id = id;
}

Board::Board(int size) {
    this->size = size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->cells[i][j] = '~';
        }
    }
}

int Board::getSize() {
    return size;
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

void Board::placeShipsRandom() {
    Carrier* carrier = new Carrier();
    Destroyer* destroyer = new Destroyer();
    Battleship* battleship = new Battleship();
    Sub* sub = new Sub();
    Ship* ships[4];
    ships[0] = carrier;
    ships[1] = destroyer;
    ships[2] = battleship;
    ships[3] = sub;
    for (int i = 0; i < 4; i++) {
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
                puts("valid");
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