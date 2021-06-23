#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

//Euclidean
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int lcm(int x,int y){
    int cand = x;
    while(cand%y != 0)
        cand += x;
    return cand;
}

int solve(int k){
    ll prev = k+1,sum=0;
    for(int j=2;j<=(2*k+1);j++){
        int h = k + j*j ;
            //int l = h>prev?lcm(h,prev):lcm(prev,h);
            //int g = h*prev/l;
        int g = h>prev?gcd(h,prev):gcd(prev,h);
        //cout<<"GCD of "<<prev<<" "<<h<<" : "<<g<<"\n";
        sum += g;
        prev = k + j*j;
    }
    return sum;
}

int main(){
    int tc,k;

    for(int i=1;i<=1000000;i++)
        cout<<solve(i)<<endl;

    cin>>tc;
    for(int i=1;i<=tc;i++){
        cin>>k;
        cout<<solve(k)<<endl;
    }

    return 0;
}

/*binary euclidean

ll gcd(ll a, ll b,ll res)
{
    if(a == b)
        return res * a;
    else if((a % 2 == 0) && (b % 2 == 0))
        return gcd(a / 2, b / 2, 2 * res);
    else if(a % 2 == 0)
        return gcd(a / 2, b, res);
    else if (b % 2 == 0)
        return gcd(a, b / 2, res);
    else if(a > b)
        return gcd(a - b, b, res);
    else
    return gcd(a, b - a, res);
}

*/
