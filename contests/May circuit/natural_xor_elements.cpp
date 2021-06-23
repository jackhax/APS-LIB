#include<iostream>
#define ll long long int

using namespace std;

int main(){
   ll tc;
   cin>>tc;
   while(tc--){
    ll n;
    cin>>n;
    if(n%4==1)
        cout<<1<<" "<<1;
    else if(n%4==2)
        cout<<"2 "<<n<<" 1";
    else if(n%4==3)
        cout<<0;
    else if(n%4==0)
        cout<<"1 "<<n;
    cout<<endl;
   }
   return 0;
}
