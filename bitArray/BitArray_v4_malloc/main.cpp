/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 17 de julio de 2018, 11:10 AM
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <unordered_set>

#define LIMIT_SIZE_RAM 11184810
#define LIMIT_SIZE_HDD 1048576

using namespace std;
/* pseudo code  
    a[0] = S (modulo 2^31)
    for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)
*/

void saveFile(vector<unsigned int> a, string name){
    fstream fs;
    fs.open (name , std::fstream::in | std::fstream::out | std::fstream::app);
    for(unsigned int i = 0; i < a.size(); i++){
        fs << a[i] << ' ';
    }
    fs.close();
}
//         int *array = (int *)malloc(100000000*sizeof(int));
int main() {
    unsigned int N, S, P, Q; // = 3 1 1 1
    cin >> N >> S >> P >> Q;
              
    try{
        unsigned int powresult = pow(2,31);
        unsigned int* a =   (unsigned int*)malloc(N*sizeof(int));
                
        a[0] = ( S % powresult ); 
        for(int i = 1; i < N; i++){                           
            a[i]= ((a[i - 1] * P + Q) % powresult);           
        }
        unordered_set<int> s(a, a + N);        
        cout << s.size() << endl;         
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    catch(exception& e){
        cerr << "exception: " << 1 << endl;
    }          
    return 0;
}