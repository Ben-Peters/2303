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
    bool pawn;
protected:
    explicit CheckerPiece(CheckerPiece *pPiece);

public:

    typedef struct{
        CheckerPiece* newPiece;
        bool jump;
        int numJumped;
        bool king;
    }PossibleMove;
    CheckerPiece(int,int,bool);
    virtual ~CheckerPiece();
    int getRow();
    int getCol();
    bool getRed();
    bool getPawn();
    void setRow(int);
    void setCol(int);
    void setRed(bool);
    virtual CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
    CheckerPiece(Pawn *pPawn);

    CheckerPiece(King *pKing);
};

class Pawn : public CheckerPiece{
private:
    int row, col;
    bool red, pawn;
public:
    Pawn(int row, int col, bool red);
    virtual ~Pawn();
    bool getPawn();
    CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
};

class King : public CheckerPiece{
private:
    int row, col;
    bool red,pawn;
public:
    King(int, int, bool);

    virtual ~King();
    bool getPawn();
    CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
};

#endif //HW5_CHECKERPIECE_H
