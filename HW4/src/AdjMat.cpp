//
// Created by Ben on 2/25/2020.
//

#include "AdjMat.h"
#include <stdio.h>

AdjMatrix::AdjMatrix() {}

AdjMatrix::~AdjMatrix() {}

void AdjMatrix::init(AdjMat *adjMP) {
    int ncols = adjMP->n;
    printf("In init with ncols = %d\n", ncols);
    for (int row = 0; row < ncols; row++) {
        for (int col = 0; col < ncols; col++) {
            *((adjMP->edgesP) + (row * ncols) + col) = 0;
        }
    }

}

void AdjMatrix::setEdge(AdjMat *adjMP, int row, int col) {
    int ncols = adjMP->n;
    int *arrayBeginning = adjMP->edgesP;
    *(arrayBeginning + (ncols * row) + col) = 1;
    *(arrayBeginning + (ncols * col) + row) = 1;
}

int AdjMatrix::getEdge(AdjMat *adjMP, int row, int col) {
    int ncols = adjMP->n;
    int *arrayBeginning = adjMP->edgesP;
    return *(arrayBeginning + (ncols * row) + col);
}