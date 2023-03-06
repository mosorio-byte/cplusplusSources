/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 4 de julio de 2018, 03:57 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double num_input[4];
    for(int i = 0; i < 4; i++){
        cin >> num_input[i];
    }
    double mayor = num_input[0];
    for(int i = 0; i < 4; i++){
        if(num_input[i]>mayor)
            mayor = num_input[i];
    }
    cout << "mayor: " << mayor << endl;
    return 0;    
}

