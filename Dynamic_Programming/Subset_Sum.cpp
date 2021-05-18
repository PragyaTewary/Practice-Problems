#include<bits/stdc++.h>
using namespace std;


// We are given an array of positive integers and a sum. 
// We need to find count of subset of arrays whose sum is equal to given sum.


int CountSubsets(int arr[], int n, int sum)
{
    int dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 1;
    }
    for(int j=1; j<=sum; j++)
    {
        dp[0][j] = 0;
    }

    // dp[i][j] : Count of subsets in arr[0 ------- i-1] with sum j.

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j < arr[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
        }

    }
    return dp[n][sum];

}


int main()
{
    int arr[] = {10, 5, 2, 3, 6, 11, 1};
    int sum = 11;
    int n= 7;       // Size of given array


    cout<< CountSubsets(arr, n, sum);
}