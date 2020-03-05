//
// Created by Ben on 2/29/2020.
//

#ifndef HW5_KING_H
#define HW5_KING_H

#include "CheckerPiece.h"
#include "CheckerPiece.cpp"

class King : public CheckerPiece{
private:
    int row, col;
    bool red;
public:
    King(int, int, bool);

    virtual ~King();

    CheckerPiece::PossibleMove *getAllPossibleMoves(CheckerPiece *);
};


#endif //HW5_KING_H
