/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 24 de junio de 2018, 08:52 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

struct Crack {
    static void nice(){
        cout << "nice" << endl;
    }
};

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
            cout << "n:" << n << " x:" << x << " y:" << y << endl;
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
             cout << "x:" << x << " y:" << y << endl;
             int dummy[sizeof...(digits)] = { (std::cout << digits << endl, 0)... };
             cout << "sizeof: " << sizeof...(digits) << endl;
  	}
        
};

int main(int argc, char** argv) {
    CheckValues<0>::check(65,65);
    CheckValues<6>::check(1, 3);
    
    Crack::nice();
    return 0;
}

