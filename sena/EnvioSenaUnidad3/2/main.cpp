/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 10 de julio de 2018, 10:00 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int T;    
    cout << "ingrese los estudiantes a ingresar:";
    cin >> T;
    
    double** list = new double*[T];
    for(int i = 0; i < T; ++i)
        list[i] = new double[3];
                
    double average[3];
    for(int i = 0; i < 3; i++)
        average[0] = 0;
    
    for(int i = 0; i < T; i++){
        cout << "estudiante " << i + 1 << endl;
        for(int j = 0; j < 3; j++){
            cout << "nota " << j + 1 << ":" << endl;
            cin >> list[i][j];
            average[j] += list[i][j]/3;
        }        
    }
    cout << "resultados" << endl;
    int count = 0;
    for(int i = 0; i < T; i++){
        cout << "estudiante " << i + 1 << " con promedio de " << average[i] << endl;
        if(average[i] > 3 )
            count++;
    }
    cout << count << " estudiantes obtuvieron mas de 3.0." << endl;
    return 0;
}
