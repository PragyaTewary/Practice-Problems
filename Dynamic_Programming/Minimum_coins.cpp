#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

//You are given an integer array coins representing coins of different denominations
//and an integer amount representing a total amount of money.
//Return the fewest number of coins that you need to make up that amount.
//If that amount of money cannot be made up by any combination of the coins, return -1.
//You may assume that you have an infinite number of each kind of coin.


int GetMin(vector<int>& coins, int amount) 
{
        int dp[amount+1];
        int n = coins.size();
        dp[0] = 0;
        for(int i=1; i<= amount; i++)
        {
            dp[i] = INT_MAX;
        }

        for(int i=1; i<= amount; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(coins[j] <= i)
                {
                    int sub_res = dp[i- coins[j]];
                    if(sub_res != INT_MAX)
                    {
                        dp[i] = min(dp[i], sub_res +1);
                    }    
                    
                }   
                
            }
            
        }
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
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
    cout <<"Number of minimum coins required to make the amount : " << GetMin(coins, amount);

}