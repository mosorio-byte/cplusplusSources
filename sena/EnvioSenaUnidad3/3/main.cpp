/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 10 de julio de 2018, 10:31 AM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void ordenaraArreglo(int *array){
    //sort
    sort(array, array + 10);
}
/*
 * 
 */
int main(int argc, char** argv) {
    int array[10];
    int beforearray[10];
    
    cout << "ingrese los numeros a ordenar:" << endl;
    for(int i = 0; i < 10; i++){
        cout << "num:";
        cin >> array[i];
        beforearray[i] = array[i];
    }

    ordenaraArreglo(array);
    
    cout << "antes:" << endl;
    for(int i = 0; i < 10; i++){
        cout << beforearray[i] << " ";        
    }
    cout << endl << "despues:" << endl;
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";        
    }
    return 0;
}

