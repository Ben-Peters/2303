//
// Created by Ben on 2/29/2020.
//

#ifndef HW5_PAWN_H
#define HW5_PAWN_H
#include "CheckerPiece.h"

class Pawn : public CheckerPiece {
private:
    int row,col;
    bool red;
public:
    Pawn();
    virtual ~Pawn();
    CheckerPiece* getAllPossibleMoves();
};

#endif //HW5_PAWN_H
