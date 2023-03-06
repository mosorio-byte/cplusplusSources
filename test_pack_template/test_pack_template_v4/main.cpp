/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 25 de junio de 2018, 08:26 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


template<typename... Ts> void func(Ts... args){
    const int size = sizeof...(args) + 2;
    int res[size] = {1,args...,2};
    for(int i = 0; i < size; i++){
        cout << "i[" << i << "]:" << res[i] << endl;
    }
    // since initializer lists guarantee sequencing, this can be used to
    // call a function on each element of a pack, in order:
    cout << "sizeof: " << sizeof...(Ts) << endl;
    int dummy[sizeof...(Ts)] = { (std::cout << args, 0)... };
}

int main(int argc, char** argv) {
    func(1,2,3,4,5,6,7);
    cout << crk<1>();
    return 0;
}

