#include <bits/stdc++.h>
using namespace std;


// Given a string S with repeated characters.
// The task is to rearrange characters in a string such that no two adjacent characters are the same. 
// Return the modified string. If the string cannot be modified return empty string.
 

string rearrangeString(string str)
{
    string res = "";
    unordered_map<char, int> mp;
    int n= str.length();
    priority_queue<pair<int, char>> pq;
    for(int i=0; i< n; i++)
    {
        mp[str[i]]++;
    }
    
    for(auto x: mp)
    {
        pq.push({x.second, x.first});
    }
   
    while(pq.size() >= 2)
    {
        pair<int, char> p1 = pq.top();
        pq.pop();
        res.push_back(p1.second);

        pair<int, char> p2 = pq.top();
        pq.pop();
        res.push_back(p2.second);
        mp[p1.second]--;
        mp[p2.second]--;
        p1.first--;
        p2.first--;
        if(mp[p1.second] > 0)
        {
            pq.push({p1.first, p1.second}); 
        }
        if(mp[p2.second] > 0)
        {
            pq.push({p2.first, p2.second});
        }
    }
    if(pq.size() == 1)
    {
        pair<int, char> last = pq.top();
        if(last.first == 1)
        {
            res.push_back(last.second);            
            return res;
        }
        else
        {
            return "";
        }
    }
    
    return res;
}


int main() 
{

    string s;
    cin>>s;

    string ans = rearrangeString(s);
    if(ans.length()==0)
        cout <<"String cannot be modified."<<endl;
    else
        cout <<ans<<endl;

	
	return 0;
} 