#include<iostream>

using namespace std;

int main(){
    int arr[] = {1,9,2,4,6,7,8,9,10,0}
    int count = 0;
    int curr_count = 0;
    int max = -1;
    for(int i=1;i<9;i++){
        j = i-1;
        k = i+1;

        if(arr[k]+arr[j] == 2*arr[i]){
            curr_count ++
        }else{
            if(curr_count>count){
                count = curr_count;
                curr_count = 0
            }
        }
    }
    cout<<cout<<endl;

    return 0;
}
