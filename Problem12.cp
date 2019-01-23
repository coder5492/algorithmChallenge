#include <bits/stdc++.h>
using namespace std;

int dp[100];

int numWays(int n)
{
    if(n == 0)
        return 1;
    else if(n<0)
        return 0;
    else if(dp[n] != -1)
        return dp[n];
    else
    {
        dp[n] = numWays(n-1) + numWays(n-2);
        return(dp[n]);
    }
}

int main() {
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<numWays(n);
	return 0;
}