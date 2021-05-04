#include<iostream>
using namespace std;
//20. Longest increasing subsequence
template<typename T>
int longest_increasing_subseq(T *arr,int n){
    int lis[n];
    for(int i=0;i<n;i++)
        lis[i] = 1;
    int l = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i] = lis[j]+1;
                if(lis[i]>l)
                    l = lis[i];
            }
        }
    }
    return l;
}
