#include<bits/stdc++.h>
using namespace std;

// Given a binary array arr of size N and an integer M.
// Find the maximum number of consecutive 1's produced by flipping at most M 0's.
// Time Complexity: O(N)
// Auxiliary Space: O(1)
// Example:
// Input: 
// N = 11
// arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
// M = 2
// Output:
// 8
 

int findZeroes(int arr[], int n, int m) 
{
    int i=0;
    int j;
    for(j=0; j<n; j++)
    {
        if(arr[j] == 0)
        {
            m--;
        }
        if(m<0 && arr[i++] == 0)
        {
            m++;
        }
    }
    return (j-i);
}  

int main() {

    int n, i, m;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    
    auto ans = findZeroes(arr, n, m);
    cout << ans << "\n";
    return 0;
}
