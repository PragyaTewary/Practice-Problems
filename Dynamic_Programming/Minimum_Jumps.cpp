#include<iostream>
#include<limits.h>
using namespace std;

//We are given an array where every value represents the maximum number of jumps
//we can make from that particular point in the array.
//We need to find out minimum number of jumps required to reach the last index in the given array from the first index.


int minJumps(int arr[], int n)
{
    int dp[n];
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        dp[i] = INT_MAX;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[j] >= i-j)
            {
                if(dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
}


int main()
{
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of array ";

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout <<"Minimum jumps required to reach index "<< n-1<<" from index 0 : " << minJumps(arr, n);
}