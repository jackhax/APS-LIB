#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<string> s,int n){
    for(int i=0;i<n;i++){
        int u=0;
        int l=0;
        for(int j=0;j<s[i].length();j++){
            int ascii = s[i][j];
            if(ascii>=110 && ascii<=122)
                return false;
            if(ascii>=65 && ascii<=77)
                return false;
            if(s[i][j]>=97 && s[i][j]<=122){
                l++;
            }   
            else
                u++;
            if(u>0 && l>0)
                return false;
        }
    }
    return true;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<string> s(n,"");
        for(int i=0;i<n;i++)
            cin>>s[i];
        if(solve(s,n))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}