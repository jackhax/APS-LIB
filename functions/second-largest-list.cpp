0//score:72.97
#include <stdio.h>

int main() {
    long long int largest,secondLargest,num;
    long long int n,i;
    scanf("%lld",&n);
    if(n<2){
        printf("-1");
        return 0;
    }

    for(i=0;i<n;i++){
        scanf("%lld",&num);
        if(i==0){
            largest = num;
            secondLargest = num;
        }
        if(num>largest){
            secondLargest = largest;
            largest = num;
        }
        else if((secondLargest==largest && num<largest))
            secondLargest = num;
        else if(secondLargest<num && largest>num)
            secondLargest = num;
    }

    if(secondLargest == largest)
        printf("-1");
    else
        printf("%lld",secondLargest);

    return 0;
}
