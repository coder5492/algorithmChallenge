#include <bits/stdc++.h>
using namespace std;

string findLargestSubstring(string str, int k)
{
    int uniqueLetters = 0,start=0,end=0,ansBegin,ansEnd,maxLen=-1,len;
    map<char,int>mp;
    
    while(start<=end)
    {
        len = end - start;
        
        if(uniqueLetters <= k && end<str.length())
        {
            if(!mp[str[end]])
                uniqueLetters++;
            mp[str[end]]++;
            
            if(len>maxLen && uniqueLetters <= k)
            {
                maxLen = len;
                ansBegin = start;
                ansEnd   = end;
            }
            
            end++;
        }
        else
        {
            mp[str[start]]--;
            if(!mp[str[start]])
                uniqueLetters--;
            start++;
        }
    }
    
    string ans = str.substr(ansBegin,ansEnd-ansBegin+1);
    return ans;
}

int main() {
    int k;
    string str;
    cin>>k>>str;
    cout<<findLargestSubstring(str,k);
	return 0;
}