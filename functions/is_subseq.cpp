#include<iostream>
using namespace std;



bool subseq(string a,string b){
    long int m = a.length();
    long int n = b.length();

    if(m>n)
        return false;
    if(m==n)
        return a == b;

    int last = -2;
    for(int i=0;i<n;i++)
        if(a[0] == b[i]){
            last = -1;
            break;
        }

    if(last == -2)
        return false;


    for(long int i=1;i<m;i++){
        int flag = 0;
        for(long int j=0;j<n;j++){
            if(b[j] == a[i] && j>=last){
                last = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0 && last >= 0)
            return false;
    }
    return true;
}

int main(){
    cout<<subseq("asyixm","coronaviruswertyuiopasdfghjklxcvbnm");
    return 0;
}
