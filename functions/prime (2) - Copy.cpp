#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
  ll z,i,j,k,temp,pro ;
  cin>>z;
  ll zroot ;
  zroot = sqrt(z);
  ll number = z ;
  ll primes[number+1];

    for(i = 2; i<=number; i++)
        primes[i] = i;
i = 2;
    while ((i*i) <= number)
    {
        if (primes[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (primes[i]*j > number)
                    break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }
    int flag = 0 ;
    up : number-=1;
    for(j = 2 ; j<=number ;j++)
    for(i = 2; i<=number; i++)
    {
        if (primes[i]!=0)
        {
          if(primes[i]*primes[j]==z)
          cout<<primes[i]<<" "<<primes[j]<<endl;
          flag = 1 ;
        }

    }
    if(flag==0)
    goto up;

}
int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
  int t,i ;
  cin>>t;
  for(i = 1 ; i <=t ; i++ )
  {
    cout<<"Case #"<<i<<":"<<" ";
    solve();
  }
  return 0 ;
}
