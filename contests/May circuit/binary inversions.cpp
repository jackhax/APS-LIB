#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int

using namespace std;

int main(){
    ll n,a,x;
    //n: arr len ; x:no. of inversions ; a:no. of zeros
    cin>>n>>a>>x;
    ll b = n-a;
    if(x>a*b){
        cout<<-1<<endl;
        return 0;
    }
    ll q = x/b;
    ll r = x%b;

    vector<ll> w(n-q-b-1,0);
    vector<ll> xx(r,1);
    vector<ll> y(1,0);
    vector<ll> z(b-r,1);
    vector<ll> zz(q,0);

    w.insert(w.end(),xx.begin(),xx.end());
    w.insert(w.end(),y.begin(),y.end());
    w.insert(w.end(),z.begin(),z.end());
    w.insert(w.end(),zz.begin(),zz.end());


    for(int i=0;i<n;i++)
        cout<<w[i]<<" ";

    return 0;
}
