#include <iostream>
#include "help.h"
#include "matrix.h"
using namespace foo;
Matrix::Matrix() {
    this->m = 0;
    this->n = 0;
    this->count = 0;    
    this->numbers = nullptr;
    this->coord = nullptr;
}
Matrix::Matrix(int m, int n, int count, int *numbers, std::pair <int, int> *coord){
    this->m = m;
    this->n = n;
    this->count = count;
    this->numbers = new int[count];
    this->coord = new std::pair<int, int>[count]; 
    for (int i = 0; i < count; i++){    
        this->numbers[i] = numbers[i];
        this->coord[i] = coord[i];
    }    
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
int* Matrix::getNumbers(){
    return this->numbers;
}
int* Matrix::getCoord(){
    return this->coord;
}
void Matrix::print(){
    std::cout<<this->m<<"x"<<this->n<<" count: "<<this->count<<std::endl;
    for (int i = 0; i < this->count; i++){
        std::cout<<this->numbers[i]<<"-("<<this->coord[i].first<<","<<this->coord[i].second<<")"<<std::endl;
    }
}
