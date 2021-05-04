#include<iostream>

using namespace std;

string toggle_case(string a){
    int l = a.length();
    for(int i=0;i<l;i++){
        if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
            if(a[i]>=97)
                a[i] = a[i] & (~32);
            else
                a[i] = a[i] | 32;
    }
    return a;
}
