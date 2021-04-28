#include<iostream>
#include<string.h>
using namespace std;

//Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
//You have the following three operations permitted on a word:
// 1- Insert a character
// 2- Delete a character
// 3- Replace a character


int minDistance(string word1, string word2) 
{
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)
            dp[i][0] = i;
        for(int j=0; j<=n; j++)
            dp[0][j] = j;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) ;  
            }
        }
        return dp[m][n];
}

int main()
{
    string s1="SATURDAY", s2="SUNDAY";

    cout << minDistance(s1, s2);
}