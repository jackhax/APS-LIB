#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void disp(vector<ll> mat){
    cout<<endl;
    for(int i=0;i<mat.size();i++){
        cout<<mat[i]<<" ";
    }
}

ll get_i(vector<ll> v,ll pos){
    //disp(v);
    cout<<endl;
    ll sum = 0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum >= pos)
            return i;
    }
    return -1;
}

int main(){
    ll m,n,x,q;
    cin>>m>>n>>x>>q;
    vector<ll> mat(m+n+2,0);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            mat[i+j]++;
        }

    while(q--){
        int t;
        cin>>t;
        if(t==1 || t==2){
            ll r,c1,c2;
            cin>>r>>c1>>c2;
            for(int i=c1;i<=c2;i++)
                mat[r+i]--;
        }else if(t==3){
            ll a;
            cin>>a;
            cout<<get_i(mat,a)+x<<endl;
        }
    }
    return 0;

}

