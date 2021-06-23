#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;
long mod = 10000007;

int main(){
    ll tc;
    cin>>tc;
    while(tc--){
        ll n,m;
        cin>>n>>m;
        ll a = m/2;
        ll b = m - a;
        cout<<"a: "<<a<<"b: "<<b<<endl;
        cout<<pow(2,a)*pow(2,b);
    }
    return 0;
}