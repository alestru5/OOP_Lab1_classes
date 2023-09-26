#include <iostream>
#include "matrix.h"
#include "help.h"

using namespace foo;
bool chet(Matrix matrix, int x){
    if (matrix.getNumbers()[x].data % 2 == 0){
        return true;
    }
    return false;
}
//(унарный !), (бинарный +-), (++ --), (+= -=), ([] 2 ), (ввод вывод >> <<), (<=>)
int main(){
    try{
        Matrix first(input());
        std::cout<<"Your matrix: "<<std::endl;
        first.print();
        Matrix second(first, callback(getCallback()));
        std::cout<<"Final matrix: "<<std::endl;
        second.print();
    } catch(const std::bad_alloc &ba){
        std::cerr<<"Not enough memory"<<std::endl;
        return 1;    
    } catch(const std::exception &e) {
        std::cerr << e.what()<<std::endl;
        return 1;
    }  
    return 0;
}   