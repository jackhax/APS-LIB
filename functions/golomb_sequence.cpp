#include<iostream>
//1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ……
void printGolomb(int n)
{
    int dp[n + 1];
    dp[1] = 1;
    cout << dp[1] << " ";
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        cout << dp[i] << " ";
    }
}