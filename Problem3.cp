#include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here
	#define FOR0(i,n) for(i=0;i<n;i++)
    #define FOR(i,j,n) for(i=j;i<n;i++)
    #define FORD(i,j,k) for(i=j;i>=k;i--)
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define inf 1000000000
	typedef long long ll;
	typedef pair<int,int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    
    
    int n,i,x,low=10000;
    int a[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        a[x] = 1;
        if(x<low)
            low=x;
    }
    i = low;
    while(1)
    {
        i++;
        if(a[i] != 1 && i>0) 
        {
            cout<<i;
            break;
        }
    }
    
	return 0;
}
    