#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

namespace foo{
    struct Element{
        int data;
        std::pair<int, int> coord;
    };
    class Matrix{
        private:
            int m;
            int n;
            int count;
            Element *numbers;
        public:
            Matrix();
            Matrix(int m, int n, int count, Element *numbers);
            Matrix(const Matrix& other);
            Matrix(Matrix& other, bool (*action)(Matrix &matrix, int x));
            ~Matrix();
            int getM();
            int getN();
            int getCount();
            Element* getNumbers();
            void print();    
    };
}
#endif