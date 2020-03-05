//
// Created by Ben on 3/2/2020.
//

#ifndef HW5_CHECKERPIECE_H
#define HW5_CHECKERPIECE_H


//#include "Pawn.h"
#include "King.h"

class CheckerPiece {
private:
    int row;
    int col;
    bool red;
public:
    typedef struct{
        CheckerPiece* newPiece;
        bool jump;
        int numJumped;
        CheckerPiece* jumped;
        bool king;
    }PossibleMove;
    CheckerPiece(int,int,bool);
    virtual ~CheckerPiece();
    int getRow();
    int getCol();
    bool getRed();
    void setRow(int);
    void setCol(int);
    void setRed(bool);

    PossibleMove *getAllPossibleMoves(CheckerPiece *);
};


#endif //HW5_CHECKERPIECE_H
