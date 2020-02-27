//
// Created by Ben on 2/25/2020.
//

#ifndef HW4_ADJMAT_H
#define HW4_ADJMAT_H


class AdjMatrix {
public:
    AdjMatrix();
    virtual ~AdjMatrix();
    typedef struct
    {
        int n;
        int* edgesP;
    }AdjMat;
    static void setEdge(AdjMat* adjMP, int row, int col);
    static int getEdge(AdjMat* adjMP, int row, int col);
    static void init(AdjMat* adjMP);
};


#endif //HW4_ADJMAT_H
