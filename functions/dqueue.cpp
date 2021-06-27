#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

int main(){
    ll tc;
    cin>>tc;
    while(tc--){
        ll n,m;
        cin>>n>>m;
        vector<ll> pos(n+1,-1);
        vector<ll> arr(n,0);
        for(int i=0;i<m;i++){
            cin>>arr[i];
            if(pos[arr[i]] == -1)
                pos[arr[i]] = i;
            else if(i>n/2)
                pos[arr[i]] = i;
        }

        ll p = pos[n];
        ll begin = 0;
        ll end = 0;
        for(int i=n-1;i>=1;i--){
            if(p>n/2 && pos[i]>p)
                end = p;
            else if(p<n/2 && pos[i]<p)
                begin = p;
            else if(p>n/2 && pos[i]<p && pos[i] >n/2)
                end = p;
            else if(p<n/2 && pos[i]>p && pos[i] <= n/2)
                begin = p;
        }
        cout<<begin + (n-end)<<endl;

    }
}