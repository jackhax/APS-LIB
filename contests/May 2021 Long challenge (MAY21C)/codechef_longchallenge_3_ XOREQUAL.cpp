#include<iostream>
#include<cmath>

#define ull unsigned long long
#define MODULO 1000000007

using namespace std;

//fastest way to compute 2^n
ull solve(ull n)
{
    ull ret = 1;
    ull a = 2;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(){
    unsigned int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++){
        ull n;
        cin>>n;
        ull c = solve(n-1);
        cout<<c;
        if(t<tc)
            cout<<endl;
    }
    return 0;
}

/*
For a given N, find the number of ways to choose an integer x from the range [0,2N−1] such that x⊕(x+1)=(x+2)⊕(x+3), where ⊕ denotes the bitwise XOR operator.

Since the number of valid x can be large, output it modulo 109+7.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains a single integer N.
Output
For each test case, output in a single line the answer to the problem modulo 109+7.

Constraints
1≤T≤105
1≤N≤105
Subtasks
Subtask #1 (100 points): Original Constraints

Sample Input
2
1
2
Sample Output
1
2
Explanation
Test Case 1: The possible values of x are {0}.

Test Case 2: The possible values of x are {0,2}.
*/
