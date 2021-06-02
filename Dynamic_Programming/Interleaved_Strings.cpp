#include <bits/stdc++.h>
using namespace std;

// Given three strings A, B and C your task is to complete the function isInterleave
// which returns true if C is an interleaving of A and B else returns false.
// C is said to be interleaving A and B,
// if it contains all characters of A and B and order of all characters in individual strings is preserved.


bool isInterleave(string s1, string s2, string s3) 
{
    int m = s1.length();
    int n = s2.length();
    bool dp[m+1][n+1];
    
    if((m+n) != s3.length())
        return false;
    
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = true;
            else if(i==0)
            {
                if(s2[j-1] == s3[j-1])
                    dp[i][j] = dp[i][j-1];
            }
            else if(j==0)
            {
                if(s1[i-1] == s3[i-1])
                    dp[i][j] = dp[i-1][j];
            }
            else if(s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else if(s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1])
            {
                dp[i][j] = dp[i][j-1];
            }
            else if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
            {
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]) ;
            }
        }
    }
    return dp[m][n];
}

int main() 
{

    string a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;

    cout << isInterleave(a,b,c)<<endl;

	
	return 0;
} 