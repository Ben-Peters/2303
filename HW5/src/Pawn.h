//
// Created by Ben on 2/29/2020.
//

#ifndef HW5_PAWN_H
#define HW5_PAWN_H


class Pawn {
private:
    int row,col;
    bool red;
public:
    Pawn();
    Pawn(bool, int, int);
    virtual ~Pawn();
    int getRow();
    int getCol();
    bool getRed();
    void setRow(int);
    void setCol(int);
    void setRed(bool);
    int* getAllPossibleMoves();
};


#endif //HW5_PAWN_H
