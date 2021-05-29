#include<bits/stdc++.h>
using namespace std;


// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The efficient way is the one that involves the least number of multiplications.
// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) 
// where the ith matrix has the dimensions (arr[i-1] x arr[i]).
// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explaination: There are 4 matrices of dimension 40x20, 20x30, 30x10, 10x30. Say the matrices are 
// named as A, B, C, D. Out of all possible combinations, the most efficient way is (A*(B*C))*D. 
// The number of operations are - 20*30*10 + 40*20*10 + 40*10*30 = 26000.



int matrixMultiplication(int m, int arr[])
{
    int n = m-1;
    int dp[n][n];
    for(int gap=0; gap<n; gap++)
    {
        for(int i=0, j=gap; j<n; i++, j++)
        {
            if(gap==0)
            {
                dp[i][j] = 0; 
            }
            else if(gap==1)
            {
                dp[i][j] = arr[i]*arr[j]*arr[j+1];
            }
            else
            {
                int minval = INT_MAX;
                for(int k = i; k<j; k++)
                {
                    int leftcost = dp[i][k];
                    int rightcost = dp[k+1][j];
                    int mulcost = arr[i]*arr[k+1]*arr[j+1];
                    int totalcost = leftcost + rightcost + mulcost ;
                    minval = min(minval, totalcost);
                }
                dp[i][j] = minval;
            }
        }
    }
    return dp[0][n-1];
}


int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0;i < N;i++)
        cin>>arr[i];

    cout << matrixMultiplication(N, arr) << endl;

    return 0;
}