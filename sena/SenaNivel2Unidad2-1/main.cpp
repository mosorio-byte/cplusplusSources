/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 4 de julio de 2018, 03:52 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double num_input[5];
    for(int i = 0; i < 5; i++){
        cin >> num_input[i];
    }
    double average = 0;
    for(int i = 0; i < 5; i++){
        average += num_input[i];
    }
    cout << "promedio: " << average/5 << endl;
    return 0;
}

