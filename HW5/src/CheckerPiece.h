//
// Created by Ben on 3/2/2020.
//

#ifndef HW5_CHECKERPIECE_H
#define HW5_CHECKERPIECE_H


class CheckerPiece {
private:
    int row;
    int col;
    bool red;
public:
    CheckerPiece();
    virtual ~CheckerPiece();
    int getRow();
    int getCol();
    bool getRed();
    void setRow(int);
    void setCol(int);
    void setRed(bool);
    CheckerPiece* getAllPossibleMoves();
};


#endif //HW5_CHECKERPIECE_H
