/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 29 de junio de 2018, 11:25 AM
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int size_m = n*2-1;
    int matriz[size_m][size_m];
    int size_m2 = size_m;
    int z = 0;
    
    for(int i = 0, i2 = size_m2-1; i < (size_m+1)/2 ; i++,i2--){            
            for(int j = 0 + z; j < size_m2; j++){
                matriz[i][j]  = n;
                matriz[i2][j] = n;
                matriz[j][i]  = n;
                matriz[j][i2] = n;
            } 
        n--;
        z++;        
        size_m2--;
    }
    
    //print the matriz
    for(int i = 0; i < size_m; i++){
            for(int j = 0; j < size_m; j++){
                printf("%d ",matriz[i][j]);
            }
        printf("\n");
    }
    return 0;
}