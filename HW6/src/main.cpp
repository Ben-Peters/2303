//
// Created by Tom Nurse on 3/7/20.
//

#include "Tests.h"
#include "Production.h"

int main(int argc, char* argv[]) {
    Tests* tests = new Tests();
    if(tests->tests())
    {
//        Production* prod = new Production();
//        if(prod->prod(argc, argv))
//        {
//            //
//        }
//        delete(prod);
    }
    else
    {
        //cout <<"Not all tests passed." << endl;
    }
    delete(tests);
    return 0;
}