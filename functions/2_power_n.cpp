#include<iostream>
#include<cmath>

#define ull unsigned long long
#define MODULO 1000000007

using namespace std;

//fastest way to compute 2^n % 1000000007
ull solve(ull n)
{
    ull ret = 1;
    ull a = 2;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(){
    cout<<solve(100);
    return 0;
}
