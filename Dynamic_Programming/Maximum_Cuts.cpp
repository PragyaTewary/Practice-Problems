#include<iostream>
using namespace std;

// Given an integer N denoting the Length of a line segment. 
// You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z.
// Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.
// Return the number of maximum cuts.
// Time Complexity : O(N)
// Auxiliary Space: O(N)

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    dp[0] = 0; 
    int vals[] = {x, y, z};
    for(int i=1; i<=n; i++)
    {
        dp[i] = -1;
        if(i>=x)
        {
            dp[i] = max(dp[i], dp[i-x]);
        }
        if(i>=y)
        {
            dp[i] = max(dp[i], dp[i-y]);
        }
        if(i>=z)
        {
            dp[i] = max(dp[i], dp[i-z]);
        }
        if(dp[i] != -1)
        {
            dp[i] = dp[i]+1;
        }
        
    }
    return max(dp[n], 0);
}

int main() {
    
    
    //taking length of line segment
    int n;
    cin >> n;
    
    //taking types of segments
    int x,y,z;
    cin>>x>>y>>z;
    
    //calling function maximizeTheCuts()
    cout<< maximizeTheCuts(n,x,y,z) <<endl;


	return 0;
}  