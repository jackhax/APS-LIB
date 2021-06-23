#include <bits/stdc++.h>
using namespace std;

bool is_integer(float k)
{
  return floor(k) == k;
}

int main(){
    double a,b,c;
    double res;
    cin>>a>>b>>c;
    if(a>=0 && a<=1)
        res = log2(1+b*c);
    else if(a>b)
        res = c*log2(a);
    else if(b>a){
        long long int  n = (1+b-a)/(b*(a-1)) + 1;
        res = log2(1+n*b) + (c-n)*log2(a);
    }
    if(is_integer(res)){
        long long int r = res;
        cout<<r;
    }else
    cout<<res;
    return 0;
}
