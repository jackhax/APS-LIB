#include<iostream>

/*To find number of combinations possible to get a number using sums of 3,5,10

ex: for 15 there are 3 ways
i.e 3+3+3+3+3 , 5+5+5 , 10+5

*/

using namespace std;

int comb(int n){
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

int main(){
    int n;
    cin>>n;
    n = comb(n);
    cout<<endl<<n<<endl;
    return 0;
}
