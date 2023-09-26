#include "help.h"
#include "matrix.h"

bool cmp(Element &a, Element &b){
    if (a.coord.first < b.coord.first) return true;
    if (a.coord.first > b.coord.first) return false;
    if (a.coord.second < b.coord.second) return true;
    if (a.coord.second > b.coord.second) return false;
    return a.data < b.data;
}

int getCallback(){
    try{
        std::cout<<"Enter filter:"<<std::endl;
        std::string msg[3]{"Even numbers", "Unique numbers", "Along numbers"};
        for (size_t i = 0; i < sizeof(msg) / sizeof(msg[0]); i++){
            std::cout<<i + 1<<". "<<msg[i]<<std::endl;
        }
        int a = getNum<int>(1, 3);
        return a;
    } catch(...){
        throw;
    }    
}

bool filter_chet(Matrix &matrix, int x){
    if (matrix.getNumbers()[x].data % 2 == 0){
        return true;
    }
    return false;
}

bool filter_unique(Matrix &matrix, int x){
    int count = 0;
    for (int i = 0; i < matrix.getCount(); i++){
        if (matrix.getNumbers()[i].data == matrix.getNumbers()[x].data){
            count += 1;
        }
    }
    if (count == 1){
        return true;
    }
    return false;
}

bool find(Matrix &matrix, int i, int j){
    for (int t = 0; t < matrix.getCount(); t++){
        if (matrix.getNumbers()[t].coord.first == i && matrix.getNumbers()[t].coord.second == j){
            return true;
        }
    }
    return false;
}

bool filter_ostrov(Matrix &matrix, int x){
    for (int i = matrix.getNumbers()[x].coord.first-1; i < matrix.getNumbers()[x].coord.first + 2; i++){
        if (find(matrix, i, matrix.getNumbers()[x].coord.second - 1) || find(matrix, i, matrix.getNumbers()[x].coord.second + 1)){
            return false;
        }
        if (i != matrix.getNumbers()[x].coord.first && find(matrix, i, matrix.getNumbers()[x].coord.second)){
            return false;
        }   
        
    }
    return true;
}

bool (*callback(int a))(Matrix &matrix, int x){
    if (a == 1){
        return filter_chet;
    } else if (a == 2){
        return filter_unique;
    } else {
        return filter_ostrov;
    }
}

Matrix input(){
    try{
        std::cout<<"Enter m и n:"<<std::endl;
        int m = getNum<int>(0);
        int n = getNum<int>(0);
        std::cout<<"Enter count not-zero numbers:"<<std::endl;
        int count = getNum<int>(0);
        Element *numbers = new Element[count];
        for (int i = 0; i < count; i++){
            std::cout<<"Enter " <<i + 1<<" element: ";
            int t = getNum<int>();
            while (t == 0){
                std::cout<<"Not 0, pls. Repeat: " <<std::endl;
                t = getNum<int>();
            }
            std::cout<<"Enter i and j " <<i + 1<<" element: ";
            int x = getNum<int>(0, m - 1);
            int y = getNum<int>(0, n - 1);
            numbers[i].data = t;
            numbers[i].coord = std::make_pair(x, y);
        }
        std::sort(numbers, numbers + count, cmp);
        Matrix matrix(m, n, count, numbers);
        delete [] numbers;
        std::cout<<std::endl;
        return matrix;
    }catch(...){
        throw; 
    }
}