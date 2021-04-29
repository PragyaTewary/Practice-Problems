#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

//You are given an integer array coins representing coins of different denominations
// and an integer amount representing a total amount of money.
//Return the number of combinations that make up that amount using given types of coins.
//You can have multiple supplies of each of the coin types.


int CoinChange(int amount, vector<int>& coins) 
{
        int n = coins.size();
        int dp[amount+1][n+1];
 
        for(int i=1; i<=amount; i++)
        {
            dp[i][0] = 0;
            
        }

        for(int i=0; i<=n; i++)
        {
            dp[0][i] = 1;
            
        }
    
        for(int i=1; i<=amount; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j] = dp[i][j-1];
                if(coins[j-1] <= i)
                {
                    dp[i][j] += dp[i - coins[j-1]][j];
                }    
            }    
        }    
        return dp[amount][n] ;
        
}

int main()
{
    int amount;
    cout<<"Enter the amount : ";
    cin>>amount;
    vector<int> coins;
    int n, temp;
    cout<<"Enter the number of coin types : ";
    cin>>n;
    cout<<"Enter the different types of coins : ";
    for(int i=0; i<n;i++)
    {
        cin>>temp;
        coins.push_back(temp);
    }
    cout <<"Number of comibinations : " << CoinChange(amount, coins);
}