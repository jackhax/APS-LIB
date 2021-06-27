#include<iostream>
using namespace std;

long int pow(long int a,long int b){
    if(b==0)
        return 1;
    long int res = 1;
    for(long int i=0;i<b;i++)
        res = res *a ;
    return res;
}

long int sum( int *arr, int len){
    long int s = 0;
    for(long int i=0;i<len;i++){
        s += arr[i];
    }

    return s % (pow(10,9) + 7);
}

int abs(int a){
    return a>0?a:a/-1;
}

void sum_( int *arr, int n, int q){
    long int s = sum(arr,n);
    for(int i=0;i<q;i++){
        long int qq;
        cin>>qq;
        for( int j=1;j<=abs(qq);j++){
            s += s;
        }
        cout<<s;
        if(i<q-1)
            cout<<endl;
    }
}

int main(){
    int l;
    cin>>l;
    int arr[l];
    for(int i=0;i<l;i++)
        cin>>arr[i];
    int q;
    cin>>q;
    sum_(arr,l,q);
    return 0;
}
