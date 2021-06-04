#include <bits/stdc++.h>
using namespace std;


// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first increasing, then decreasing.
// This problem is variation of Longest Increasing Subsequence.

vector<int> findlis(int n, vector<int>& arr)
{
    vector<int> lis(n);
    lis[0] =  1;
    for(int i= 1; i<n; i++)
    {
        lis[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j]+1);
            }
            
        }
    }
    return lis;
    
}


int LongestBitonicSequence(vector<int>nums)
{
    int n = nums.size();
    
    vector<int> lis = findlis(n, nums);
    reverse(nums.begin(), nums.end());
    vector<int> lds = findlis(n, nums);
    reverse(lds.begin(), lds.end());
    int res = INT_MIN;
    
    for(int i= 0; i<n; i++)
    {
        res = max(res, lis[i] + lds[i] -1);
    }
    return res;
}


int main()
{

    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = LongestBitonicSequence(nums);
    cout << ans <<"\n";
	return 0;
}