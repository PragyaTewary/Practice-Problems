#include<iostream>
#include<string.h>
using namespace std;

// Given two strings. 
// The task is to find the length of the longest common substring.

int longestCommonSubstr (string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    int res = 0;
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]= 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+ 1;
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return res;
    
}


int main()
{
    int m, n;  /// Length of s1 is m and length of s2 is n.
    cin >> m >> n;
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstr (s1, s2, m, n) << endl;
}
