/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 10 de julio de 2018, 09:23 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int T;    
    cout << "ingrese los números a digitar:";
    cin >> T;
    
    double* list = new double[T];
    int  max_num, min_num;
    double average;
    average = 0;
    
    cout << "num[" << 1 << "]:";
    cin >> list[0];
    average += list[0]/T; 
    max_num = list[0];
    min_num = list[0];
    for(int i = 1; i < T; i++){
        cout << "num[" << i + 1 << "]:";
        cin >> list[i];
        if(list[i] > max_num )
            max_num = list[i];
        if(list[i] < min_num)
            min_num = list[i];
         average += list[i]/T;
    }
    cout << "numero maximo:"  << max_num << endl;
    cout << "numero minimno:" << min_num << endl;
    cout << "promedio:" << average << endl;    
    return 0;
}

