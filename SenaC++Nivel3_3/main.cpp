#include <iostream>

using namespace std;

int main()
{
    int input_int, num_nombres;
    string input_str;
    cout << "cantidad de vendedores:";
    cin >> input_int;
    num_nombres = input_int;
    string *nombres = new string[num_nombres];
    double *promedio = new double[num_nombres];
    double** ventas = new double*[num_nombres];
        for (int i = 0; i < num_nombres; ++i)
            ventas[i] = new double[4];
    for(int i = 0; i < num_nombres;i++){
            cout << "nombre de vendedor:";
            cin >> input_str;
            nombres[i] = input_str;
            for(int j = 0; j < 4 ;j++){
                cout << "ventas mes " << j+1 << " :" ;
                cin >> input_int;
                ventas[i][j] = input_int;
            }
    }
    cout << "+++++++ informe +++++++"<< endl;
    for(int i = 0; i < num_nombres; i++){
        cout  << nombres[i] << " ";
        for(int j = 0; j < 4; j++){
            cout <<  ventas[i][j] << " ";
        }
        cout << endl;
    }

    cout << "+++++++ promedios ventas +++++++" << endl;
    for(int i = 0; i < num_nombres; i++){
        for(int j = 0; j < 4; j++){
            promedio[i] += ventas[i][j]/3;
        }
        cout << nombres[i] << ":" << promedio[i] << endl;
    }

    return 0;
}

