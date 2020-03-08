//
// Created by Tom on 3/7/20.
//

#ifndef INC_2303_TESTS_H
#define INC_2303_TESTS_H

class Tests {
public:
    Tests();
    virtual ~Tests();
    bool tests();
    static bool testInitBoard();
    static bool testPrintBoard();
    static bool testNewShip();
    static bool testUpdateBoard();
    static bool testBoundsCheck();
    static bool testDidSinkShip();
    static bool testIsValidLocation();
    static bool testWinner();
};

#endif //INC_2303_TESTS_H
