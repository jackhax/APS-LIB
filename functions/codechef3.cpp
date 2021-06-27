#include<iostream>

using namespace std;

bool canEscape(int n,int m,int x,int y,int a,int b){
    int xr = n-x;
    int yr = m-y;
    int ar = n-a;
    int br = m-b;

    if( (xr<=ar && yr<=br) || (xr<=1 || yr<=1))
        return true;
    else
        return false;
}

int main(){
    int tc,n,m,x,y,a,b;
    cin>>tc;
    for(int i=0;i<tc;i++){
        cin>>n>>m>>x>>y>>a>>b;
        if(canEscape(n,m,x,y,a,b))
            cout<<"YES";
        else
            cout<<"NO";
        if(i<tc-1)
            cout<<"\n";
    }
    return 0;
}
