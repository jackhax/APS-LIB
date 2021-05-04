#include<iostream>
#include <cstring>
#include<string.h>
using namespace std;


//1
int set_bits(int a){
    int c = 0;
    while(a){
        a = a & (a-1);
        c++;
    }
    return c;
}

//2
int unset_bits(int a){
    int c=0;
    while(a){
        if((a&1)==0)
            c++;
        a=a>>1;
    }
    return c;
}

//3
int mask_bits(int val,int mask){
    /*

    Bit-Masking means imposing mask over bits. Here is a bit-masking with AND-

     1 1 1 0 1 1 0 1   [input]
(&)  0 0 1 1 1 1 0 0    [mask]
------------------------------
     0 0 1 0 1 1 0 0  [output]

    */
    return val&mask;
}
