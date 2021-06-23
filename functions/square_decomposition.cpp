#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int *square_decomposition(int *arr,int n){

    //range minimum

    int l = sqrt(n);
    int *sq_arr = (int *)malloc(l*sizeof(int));
    int interval = n/l;
    cout<<"Interval: "<<interval<<endl;
    int min = 0;
    for(int i=0;i<n;i++){
        if(arr[min]>arr[i])
            min = i;
        if((i+1)%interval == 0 ){
            sq_arr[(i+1)/interval - 1] = arr[min];
            if(n-(i+1)>interval)
                min = i+1;
        }else if(i == n-1){
            sq_arr[l-1] = arr[min];
        }
    }
    return sq_arr;
}

int query(int *arr,int n,int *sq_arr,int l,int u){
    int m = n/sqrt(n);
    int minn = 0;
    if((l)%m == 0 && ((u+1)%m == 0 || u == n-1)){
        minn = sq_arr[(l)/m];
        for(int i=(l)/m ; i < (u)/m ; i++){
            if(minn > sq_arr[i])
                minn = sq_arr[i];
        }
    }else{
        int i = l;
        int j = u;
        minn = arr[l];
        while((i)%m != 0){
            if(minn > arr[i])
                minn = arr[i];
            i++;
        }
        while((j+1)%m != 0 && j != n-1){
            if(minn > arr[j])
                minn = arr[j];
            j--;
        }
        int min1 = query(arr,n,sq_arr,i,j);
        cout<<"minn: "<<minn<<" min1: "<<min1<<endl;
        minn = minn<min1?minn:min1;
    }
    return minn;
}

void disp(int *arr,int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {4,7,6,3,2};
    disp(arr,5);
    int *sq = square_decomposition(arr,5);
    disp(sq,2);
    cout<<query(arr,5,sq,1,3);
    return 0;
}
