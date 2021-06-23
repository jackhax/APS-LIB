#include<iostream>

 void fib (int n) {
    int fibresult[n]
    fibresult[0] = 1;
    fibresult[1] = 1;
    for (int i = 2; i<n; i++)
        fibresult[i] = fibresult[i-1] + fibresult[i-2];
}