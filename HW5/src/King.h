//
// Created by Ben on 2/29/2020.
//

#ifndef HW5_KING_H
#define HW5_KING_H
#include "CheckerPiece.h"

class King : public CheckerPiece{
private:
    int row,col;
    bool red;
public:
    King();
    virtual ~King();
    CheckerPiece* getAllPossibleMoves();
};


#endif //HW5_KING_H
