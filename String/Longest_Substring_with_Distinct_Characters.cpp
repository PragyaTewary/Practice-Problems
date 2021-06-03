#include <bits/stdc++.h>
using namespace std;

//Given a string s,
// find the length of the longest substring without repeating characters.

 

int lengthOfLongestSubstring(string s) 
{
    int res = 0;
    int i = -1;
    int j = -1;
    int n = s.length() - 1;
    unordered_map<char, int> map;
    
    while(true)
    {
        bool f1 = false;
        bool f2 = false;
        
        while(i < n)
        {

            f1 = true;
            i++;
            char ch = s[i];
            map[ch]++;
            
            /*if(map.find(ch) != map.end())
                    map[ch]++;
            else
                map.insert({ch, 1});*/

            if(map[ch] == 2)
                break;
            else
            {
                int len = i-j;
                if(len > res)
                    res = len;
            }
        }
        while(j < n)
        {
            f2 = true;
            j++;
            char ch = s[j];
            map[ch]--;
            
            if(map[ch] == 1)
                break;
        }
        
        if(f1 == false && f2 == false)
            break;
    }
    return res;
    
}

int main() 
{

    string s;
    cin>>s;

    cout << lengthOfLongestSubstring(s)<<endl;

	
	return 0;
} 