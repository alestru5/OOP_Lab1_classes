#include <iostream>
#include "matrix.h"

using namespace foo;


int main(){
    int *num = new int[1];
    std::pair <int, int> *coord = new std::pair<int, int>[1]; 
    for (int i = 0; i < 1; i++){
        num[i] = 1;
        coord[i] = std::make_pair(1, 2);
    }
    Matrix matrix(5, 5, 1, num, coord);
    matrix.print();
    return 0;
}   