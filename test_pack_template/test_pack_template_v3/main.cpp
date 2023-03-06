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


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
            CheckValues<n-1, 0, digits...>::check(x, y);
            CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static int check(int x, int y)
  	{
            cout << endl;
            cout << "x:" << x << " y:" << y << endl;
            int dummy[sizeof...(digits)] = { (std::cout << digits, 0)... };
            
            int data[sizeof...(digits)] = {digits...};           
            int result = 0;
            for(int i = 6; i != -1; i--){
                if(data[i]==true){
                    result = (result << 1) ^ 0x01;         
                }
                else{
                    result = (result << 1) ^ 0x00; 
                }
            }
            
            cout << " sizeof: " << sizeof...(digits) << " num:" << result << endl;
            return result;
  	}
        
};

int main(int argc, char** argv) {
    CheckValues<6>::check(1, 3);
    return 0;
}

