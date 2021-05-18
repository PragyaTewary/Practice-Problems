#include<bits/stdc++.h>
using namespace std;

// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by 
// deleting some or no elements without changing the order of the remaining elements.



 // Function to find largest Common subsequence of given string s1 and reverse of s1 i.e s2

int findLCS(string s1, string s2)
    {
        
        int m = s1.length();
        int n = s2.length();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)
            dp[i][0]= 0;
        for(int i=0; i<=n; i++)
            dp[0][i]= 0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
int longestPalindromeSubseq(string s1) 
    {
        string s2 = string(s1.rbegin(), s1.rend()); // Reverse string s1
        int res = findLCS(s1, s2);
        
        return res;
        
    }
    
int main()
{
    string s ="bbbabcb";

    cout<<longestPalindromeSubseq(s);
}