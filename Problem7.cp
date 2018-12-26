#include <bits/stdc++.h>
using namespace std;
 
int dp[100];

int count(string str, int start)
{
    int sum = 0;
    if(start > str.length())
        return 1;
    else if(start == str.length())
    {
        if(str[start] == '0')
            return 0;
        else
            return 1;
    }
    else
    {
        if(str[start] != '0')
            sum += count(str, start+1);
        if(str.length() > start+1 )
        {
            int first = str[start] - 48;
            int second = str[start+1] - 48;
            int num = first*10 + second;
            
            if(num <= 26 && first!=0)
            {
                sum += count(str,start+2);
            }
        }
        
        dp[start] = sum;
        return dp[start];
    }
}

int main() {
    string str= "1220";
    memset(dp, -1, sizeof(dp));
    cout<<count(str,0);
	return 0;
}