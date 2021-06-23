#include <iostream>
#include <climits>
#define ll long long int
using namespace std;

template <typename T>
void swap(T *a,T *b){
    T c = *a;
    *a = *b;
    *b = c;
}

template <typename T>
int partition (T arr[], int low, int high)
{
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//7 Quick Sort.
template <typename T>
void quick_sort(T arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void disp(ll *arr,int n){
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
	    cin>>arr[i];
	}
	quick_sort(arr,0,n-1);
    disp(arr,n);
	for(ll i=n-1;i>=0;i--){
	    if(i==0){
	        cout<<arr[0]*n<<endl;
	        break;
	    }
	    if(arr[i]*(n-i) >= arr[i-1]*(n-i+1)){
	        cout<<arr[i]*(n-i)<<endl;
	        break;
	    }
	}
	return 0;
}