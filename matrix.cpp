#include <iostream>
#include "help.h"
#include "matrix.h"
using namespace foo;
Matrix::Matrix() {
    this->m = 0;
    this->n = 0;
    this->count = 0;    
    this->numbers = nullptr;
}

Matrix::Matrix(int m, int n, int count, Element *numbers){
    this->m = m;
    this->n = n;
    this->count = count;
    this->numbers = new Element[count];
    for (int i = 0; i < count; i++){    
        this->numbers[i] = numbers[i];
    }    
}

Matrix::Matrix(const Matrix& other){
    this->m = other.m;
    this->n = other.n;
    this->count = other.count;
    this->numbers = new Element[other.count];
    for (int i = 0; i < other.count; i++){
        this->numbers[i] = other.numbers[i];
    }
}

Matrix::Matrix(Matrix& other, bool (*action)(Matrix &matrix, int x)){
    this->m = other.m;
    this->n = other.n;
    int t = 0;
    this->numbers = new Element[other.count];
    for (int i = 0; i < other.count; i++){
        if (action(other, i)){
            this->numbers[t] = other.numbers[i];
            t += 1;
        }
    }
    this->count = t;

    Element *tmp1 = new Element[t];
    std::copy(this->numbers, this->numbers + t, tmp1);
    delete [] this->numbers;
    this->numbers = tmp1;
}

Matrix::~Matrix(){
    delete [] this->numbers;
}

int Matrix::getM(){
    return this->m;
}

int Matrix::getN(){
    return this->n;
}

int Matrix::getCount(){
    return this->count;
}

Element* Matrix::getNumbers(){
    return this->numbers;
}


void Matrix::print(){
    std::cout<<this->m<<"x"<<this->n<<" count: "<<this->count<<std::endl;
    if (this->m <= 20 && this->n <= 20){
        int t = 0;
        for (int i = 0; i < this->m; i++){
            for (int j = 0; j < this->n; j++){
                if (t < this->count && this->numbers[t].coord.first == i && this->numbers[t].coord.second == j){
                    std::cout<<this->numbers[t].data<<" ";
                    t += 1;
                } else{
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }    
}


