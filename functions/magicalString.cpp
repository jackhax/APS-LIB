#include<iostream>

using namespace std;

int main(){
    string a;
    int n;
    cin>>n;
    cin>>a;
    int ans = 0;
    int i;
    for(i=1;i<=n-1;i++){
        if(i%2 == 1 && (a[i-1] == a[i])){
            ans++;
            a.erase(i,i);
            n--;
            i--;
        }
    }
    if((n-ans)%2 !=0)
        cout<<ans+1;
    else
        cout<<ans;
    return 0;
}