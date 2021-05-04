#include<iostream>
#include"jackady.h"
#include <cstring>
#include <cstdlib>

using namespace std;

template <typename T>
void swap(T *a,T *b){
    T c = *a;
    *a = *b;
    *b = c;
}

int min(int a,int b){
    return a>=b?b:a;
}

int max(int a,int b){
    return a>=b?a:b;
}

int lcs_len(string a,string b){
    int al = a.length();
    int bl = b.length();

    int mat[al+1][bl+1];

    for(int i=0;i<=al;i++)
        for(int j=0 ;j<=bl ;j++)
            if(i==0 || j==0)
                mat[i][j] = 0;

    for(int i=1 ; i<=al ; i++){
        for(int j=1 ; j<=bl ; j++){
            if(a[i-1]==b[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
        }
    }
    return mat[al][bl];
}
