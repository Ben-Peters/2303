//
// Created by Tom Nurse on 3/7/20.
//

#ifndef INC_2303_BOARD_H
#define INC_2303_BOARD_H

class Ship {
public:
    Ship();
    Ship(int size, char id, bool sunk);
    virtual ~Ship();
    int size;
    char id;
    bool sunk;
};

class Board {
public:
    char playerName[50];
    Board();
    Board(int size, char name[]);
    virtual ~Board();
    int qtyShipsLeft();
    void placeShipsRandom();
    void manuallyAddShip(Ship* ship, int index, int row, int col, char direction);
    bool isValidLocation(int row, int col, int length, char direction);
    bool checkBounds(int row, int col);
    void printBoard(bool withShips);
    void updateBoard(int row, int col);
    void addShip(Ship* ship, int row, int col, char direction);
    bool didSink();
    char getCellValue(int row, int col);

private:
    int size;
    Ship* ships[5];
    char cells[10][10];
};

#endif //INC_2303_BOARD_H
