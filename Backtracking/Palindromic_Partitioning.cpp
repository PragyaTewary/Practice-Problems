#include<bits/stdc++.h>
using namespace std;



// Given a String S, 
// Find all possible Palindromic partitions of the given String.
// Example:
// Input: S = "madam"
// Output:
// [[m a d a m], [m ada m], [madam]]



bool ispal(string s)  // To check whether the prefix string is palindrome or not
{
    int l=0, r=s.length()-1;
    while(l<r)
    {
        if(s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void findans(string str, vector<vector<string>>& res, vector<string>& v)
{
    if(str.size() == 0)
    {
        res.push_back(v);
        return;
    }
    for(int i=0; i<str.length(); i++)
    {
        string prefix = str.substr(0, i+1);
        string ros = str.substr(i+1);            //ros is rest of the string after removing prefix.
        if(ispal(prefix))
        {
            v.push_back(prefix);      // If the prefix is palindrome, add it to the vector v.
            findans(ros, res, v);
            v.pop_back();
        }
    }
}


vector<vector<string>> allPalindromicPerms(string S) 
{
    vector<vector<string>> res;
    vector<string> v;
    findans(S, res, v);
    return res;
}

int main() {
    
    string S;
    
    cin>>S;

    vector<vector<string>> ptr = allPalindromicPerms(S);
    
    for(int i=0; i<ptr.size(); i++)
    {
        for(int j=0; j<ptr[i].size(); j++)
        {
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}  