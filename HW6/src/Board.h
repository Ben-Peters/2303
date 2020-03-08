//
// Created by Tom Nurse on 3/7/20.
//

#ifndef INC_2303_BOARD_H
#define INC_2303_BOARD_H

class Ship {
public:
    Ship();
    Ship(int size, char id);
    virtual ~Ship();
    int size;
    char id;
};

class Board {
public:
    Board();
    Board(int size);
    virtual ~Board();
    int getSize();
    void placeShipsRandom();
    bool isValidLocation(int row, int col, int length, char direction);
    void printBoard(bool withShips);
    static void updateBoard(char value);
    void addShip(Ship* ship, int row, int col, char direction);
    char getCellValue(int row, int col);

private:
    int size;
    char cells[10][10];
};

#endif //INC_2303_BOARD_H
