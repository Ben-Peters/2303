//
// Created by Tom on 3/7/20.
//

#ifndef INC_2303_PRODUCTION_H
#define INC_2303_PRODUCTION_H

#include "Board.h"

class Production {
public:
    Production();
    virtual ~Production();
    static bool run(int argc, char* argv[]);
    static int promptForBoardSize();
    static int* promptForMove();
    static int checkForWinner(Board* user, Board* cpu);
};


#endif //INC_2303_PRODUCTION_H
