#ifndef HELP_H
#define HELP_H
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>

#include "matrix.h"





using namespace foo;


int getCallback();

Matrix input();

template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()){
    T a;
    while (true){
        std::cin>>a;
        if (std::cin.eof()){
            throw std::runtime_error("Failed to read number: EOF.");
        } else if (std::cin.bad()){
            throw std::runtime_error("Failed to read number.");
        } else if(std::cin.fail() || !std::cin.good()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Error, repeat, please!"<<std::endl;
        } else if (a >= min && a <= max){
            return a;
        } else{
            std::cout<<"Out of range index. Repeat, pls: ";
        }
    }
}

bool filter_chet(Matrix &matrix, int x);
bool filter_unique(Matrix &matrix, int x);
bool find(Matrix &matrix, int i, int j);
bool filter_ostrov(Matrix &matrix, int x);
bool (*callback(int a))(Matrix &matrix, int x);

#endif