#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<climits>
using namespace std;


//We are given a set of items in which their weights and values are given.
//We are also given a Knapsack capacity and our aim is to collect maximum value in the knapsack.
//One advantage is that we can collect some items partially.



bool myCmp(pair <int, int> a, pair <int, int> b)
{
    //Calculate ratio (Value / Weight) for every item.

    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1>r2 ;          
}

double FracKnapsack(int W, pair <int, int> arr[], int n)
{
    sort(arr, arr+n, myCmp);    //Sort all items in decreasing order of the ratio.
    double res = 0.0;
    for(int i=0; i<n; i++)
    {
        if(arr[i].second <= W)  //arr[i].second contains weight of the item (i+1) 
        {
            res += arr[i].first; //arr[i].first contains value of the item (i+1)
            W = W - arr[i].second;

        }  
        else
        {
            res += arr[i].first * ((double)W/arr[i].second);
            break;
        }    

    }
    return res;

}
int main()
{
    pair <int, int> arr[] = {make_pair(600, 50), make_pair(500, 20), make_pair(400, 30)};

	int n = 3, W = 70;

	cout<<FracKnapsack(W, arr, n); 

	return 0;
}