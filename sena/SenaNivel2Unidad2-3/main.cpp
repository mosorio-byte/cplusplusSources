/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 4 de julio de 2018, 04:03 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int T;
    cout << "digite cuantos numeros desea leer:";
    cin >> T;
    
    int count = 0;
    int num_input;
    for(int i = 0; i < T; i++){
        cin >> num_input;
        if(num_input>0)
            count++;
    }
    cout << "numeros positivos: " << count << endl;
    return 0;  
}

