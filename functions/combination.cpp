#include<iostrea>

using namespace std;

//8. Number of ways to get a number using sum of 3,5,10
//Ex to get 15: 3+3+3+3+3,5+5+5,10+5 there are 3 ways
int combination(int n){
    int *arr = new int(n+1);

    if(arr == NULL)
        return -1;

    for(int i=0;i<=n;i++)
        arr[i] = 0;
    arr[0] = 1;

    for(int i=3;i<=n;i++)
        arr[i] = arr[i] + arr[i-3];

    for(int i=5;i<=n;i++)
        arr[i] = arr[i] + arr[i-5];

    for(int i=10;i<=n;i++)
        arr[i] = arr[i] + arr[i-10];

    return arr[n];
}
