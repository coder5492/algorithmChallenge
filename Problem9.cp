#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,a[100],i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int last = INT_MIN, secondLast = INT_MIN, ans = INT_MIN,cur = INT_MIN;
    for(i=0;i<n;i++)
    {
        int cur = max(max(a[i], secondLast), max(last,a[i] + secondLast));
        secondLast = max(last,secondLast);
        last = cur;
        ans = max(ans,cur);
    }
    cout<<ans;
    return 0;
}