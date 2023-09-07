#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

namespace foo{
    class Matrix{
        private:
            int m;
            int n;
            int count;
            int *numbers;
            std::pair <int, int> *coord;
        public:
            Matrix();
            Matrix(int m, int n, int count, int *numbers, std::pair <int, int> *coord);
            int getM();
            int Matrix::getN();
            int Matrix::getCount();
            int* Matrix::getNumbers();
            int* Matrix::getCoord();
            void print();    
    };
}
#endif