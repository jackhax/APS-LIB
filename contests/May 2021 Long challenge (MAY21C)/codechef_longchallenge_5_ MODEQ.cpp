#include<iostream>
#include<vector>
using namespace std;
/*
int solve(int n,int m){
    int c=0;
    int *arr = mod_arr(n,m);
    disp(arr,n);
    quick_sort(arr,0,n-1);
    disp(arr,n);
    for(int i=0;i<(n-1);i++){
        if(arr[i]==arr[i+1])
            c++;
    }
    return c;
}
*/
void solve()
{
    int n,m;
    int i=0 , j=0 , k=0 ;
            cin>>n>>m;
            int ans=0;
            vector<int> arr(n+1,1);

            for(i = 2 ; i <= n ; i++)
            {
                int a=m%i;
                ans = ans + arr[a];
                for(j = a ; j <= n ; j = j+i)
                    arr[j] = arr[j]+1;
            }
        cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t  ;
	cin>>t;

	while(t--)
    {
        solve();
    }
return 0;
}
