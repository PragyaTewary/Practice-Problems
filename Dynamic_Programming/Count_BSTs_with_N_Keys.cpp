#include<bits/stdc++.h>
using namespace std;

// Given an integer n,
// return the number of structurally unique BST's (binary search trees)
// which has exactly n nodes of unique values from 1 to n.

int numTrees(int n) 
{
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = 0;
        for(int j=0; j<i; j++)
        {
            dp[i] += dp[j] * dp[i-j-1];
        }
        
    }
    return dp[n];
        
}

int main()
{
    int n;
    cin>>n;

    cout<< numTrees(n);
    return 0;
}