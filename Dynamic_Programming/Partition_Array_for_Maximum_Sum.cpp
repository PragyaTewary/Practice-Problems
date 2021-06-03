#include <bits/stdc++.h>
using namespace std;


// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
// After partitioning, each subarray has their values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning.
// Example : 
// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]



int findmax(vector<int>& arr, int i, int j)
{
    int ans = INT_MIN;
    for(int l=1; l<=j; l++)
    {
        ans = max(ans, arr[i-l]);
    }
    return ans;
}


int maxSumAfterPartitioning(vector<int>& arr, int k)
{
    int n = arr.size();
    int dp[n+1];              // dp[i] will be the answer for array arr[0], ..., arr[i-1].
    dp[0] = 0;
    for(int i = 1, j=1; i <=k; i++,j++)
    {
        dp[i] = findmax(arr, i, j)*j;
    }
    for(int i=k+1; i<=n; i++)
    {
        dp[i] = 0;
        // For j = 1 .. k that keeps everything in bounds,      
        //dp[i] is the maximum of dp[i-j] + max(arr[i-1], ..., arr[i-j]) * j .

        for(int j=1; j<=k; j++)                                                                                            
        {
            dp[i] = max(dp[i], (dp[i-j] + findmax(arr, i, j)*j));  
        }
    }
    return dp[n];
}

int main() 
{
    int n;
    cin >> n;

    vector<int> arr;

    //adding elements to the array
    for (int i = 0; i < n; i++) 
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    int k;
    cin>>k;

    cout << maxSumAfterPartitioning(arr, k) << endl;
    
    return 0;
}