//
// Created by Ben on 3/2/2020.
//

#ifndef HW5_CHECKERPIECE_H
#define HW5_CHECKERPIECE_H


//#include "Pawn.h"
//#include "King.h"

class Pawn;
class King;

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
    virtual CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
    CheckerPiece(Pawn *pPawn);
};

class Pawn : public CheckerPiece{
private:
    int row, col;
    bool red;
public:
    Pawn(int row, int col, bool red);

    virtual ~Pawn();

    CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
};

class King : public CheckerPiece{
private:
    int row, col;
    bool red;
public:
    King(int, int, bool);

    virtual ~King();

    CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
};

#endif //HW5_CHECKERPIECE_H
