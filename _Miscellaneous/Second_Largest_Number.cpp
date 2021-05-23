#include<bits/stdc++.h>
using namespace std;

// Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
// An alphanumeric string is a string consisting of lowercase English letters and digits.

 
 int secondHighest(string s) 
 {
        
        unordered_set<int> t;
        vector<int> v;
        for(int i=0; i<s.length(); i++)
        {
            if(isdigit(s[i]))
                t.insert(s[i]);
        }
        int max=0;
        for(auto itr=t.begin(); itr != t.end(); itr++)
        {
            int x = *itr - '0';
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int n = v.size();
        if(n >= 2)
        {
            return v[n-2];
        }   
        return -1;
}

int main()
{
    string s;
    cin>>s;

    cout << secondHighest(s) <<endl; 
}