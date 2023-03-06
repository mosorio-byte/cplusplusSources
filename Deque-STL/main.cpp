/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 12 de julio de 2018, 10:57 AM
 */

#include <iostream>
#include <deque> 
#include <algorithm>

using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.     
    for(int i = 0; i < (n - k + 1); i++){        
        cout << *max_element( &arr[i] , &arr[i] + k) << " ";
    }    
    cout << endl;
}

int main(){  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int* arr = new int[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}