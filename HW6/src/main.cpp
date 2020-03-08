//
// Created by Tom Nurse on 3/7/20.
//

#include "Tests.h"
#include "Production.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    Tests* tests = new Tests();
    if(tests->tests())
    {
        Production* prod = new Production();
        if(prod->run(argc, argv))
        {
            puts("Production passed");
        }
        delete(prod);
    }
    else
    {
        puts("Not all tests passed");
    }
    delete(tests);
    return 0;
}