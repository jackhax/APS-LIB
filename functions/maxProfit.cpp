#include<iostream>

using namespace std;

int maxDiff(int arr[], int n){
   // Maximum difference found so far
   int MD = arr[1] - arr[0];
   // Minimum number visited so far
   int min = arr[0];
   for(int i = 1; i < n; i++){
      if (arr[i] - min > MD)
         MD = arr[i] - min;
      if (arr[i] < min)
         min = arr[i];
   }
   return MD>0?MD:0;
}

int main(){
    int arr[] = {7,6,1,9,1,7};
    cout<<maxDiff(arr,6);
    return 0;
}
