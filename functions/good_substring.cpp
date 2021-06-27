#include<iostream>
#include<vector>
using namespace std;
int main(){
    string a;
    cin>>a;

    int c=0;

    for(int i=0;i<a.length()-2;i++){
        if(a[i] != a[i+1] && a[i] != a[i+2] && a[i+1] != a[i+2])    
            c++;
    }

    cout<<(c);
    return 0;
}