#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        long int n,m,k;
        long int plags = 0;
        cin>>n>>m>>k;
        vector<long int> v(n+1,0);
        for(int i=0;i<k;i++){
            int li;
            cin>>li;
            if(li<=n){
                v[li]++;
                if(v[li]==2){
                    plags++;
                }
            }
        }
        cout<<plags<<" ";
        for(int i=1;i<=n;i++){
            if(v[i]>1)
                cout<<i<<" ";
        }
        cout<<endl;
    }
}