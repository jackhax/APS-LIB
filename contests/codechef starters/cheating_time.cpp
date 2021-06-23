#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k,f;
        cin>>n>>k>>f;
        ll s=0,e=0;
        ll flag= 0;
        for(int i=0;i<n;i++){
            ll end;
            cin>>s>>end;
            k -= s-e;
            e = end;
            if(k<=0){
                flag = 1;
                cout<<"YES"<<endl;
                break;
            }        
        }
        if(!flag){
            if(f-e>=k)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}