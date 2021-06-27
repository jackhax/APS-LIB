#include<iostream>
#include<vector>
using namespace std;

void disp(vector<int> v,int n){
    cout<<endl;
    for(auto i = v.begin(); i != v.end() ;i++)
        cout<<*i<<" ";
}

template <typename T>
void swap(T *a,T *b){
    T c = *a;
    *a = *b;
    *b = c;
}

vector<int> rev(vector<int> v,int n){
    for(int i=0;i<n/2;i++)
        swap(v[i],v[n-1-i]);
    return v;
}

void rev1(vector<int> &v,int n){
    for(int i=0;i<n/2;i++)
        swap(v[i],v[n-1-i]);
}

int main(){

    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        v.push_back(p);
    }

    for(auto i=v.begin();i!=v.end();i++)
        cout<<*i;

    for(int i=0;i<n;i++)
        cout<<v[i];

    v = rev(v,n);
    disp(v,n);
    rev1(v,n);
    disp(v,n);

    return 0;
}
