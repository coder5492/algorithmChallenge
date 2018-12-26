#include<bits/stdc++.h>
using namespace std;

pair<int,int> cons(int a, int b)
{
    pair<int,int> p(a,b);
    return p;
}

int car(pair<int,int> p)
{
    return p.first;
}

int cdr(pair<int, int>p)
{
    return p.second;
}
int main()
{
    cout<<car(cons(3,4))<<" "<<cdr(cons(3,4));    
    
 return 1;   
}