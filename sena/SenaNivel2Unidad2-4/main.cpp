/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 4 de julio de 2018, 04:11 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
void cambiarsigno(double *num_input){
    *num_input *= -1;
}
int main(int argc, char** argv) {
    double num_input;
    cout << "cambiar signo, escribir numero: ";
    cin >> num_input;
    cambiarsigno(&num_input);
    cout << num_input << endl;
    return 0;
}

