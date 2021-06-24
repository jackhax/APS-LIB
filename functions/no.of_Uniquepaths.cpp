#include<bits/stdc++.h>
using namespace std;

 
class Solution
{
    public:
    
    int NumberOfPath(int a, int b)
    {
        int dp[a+1][b+1];
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                
                if(i==1 || j==1)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[a][b];
    }
};



int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}
