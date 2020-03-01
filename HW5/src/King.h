//
// Created by Ben on 2/29/2020.
//

#ifndef HW5_KING_H
#define HW5_KING_H


class King {
private:
    int row,col;
    bool red;
public:
    King();
    virtual ~King();
    int getRow();
    int getCol();
    bool getRed();
    void setRow(int);
    void setCol(int);
    void setRed(bool);
    int* getAllPossibleMoves();
};


#endif //HW5_KING_H
