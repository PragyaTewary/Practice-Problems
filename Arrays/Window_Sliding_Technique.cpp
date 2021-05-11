#include<bits/stdc++.h>
using namespace std;

// Given an array of integers and a number k, 
// find the maximum sum of k consecutive elements.


int findmaxsum(vector<int> v, int k)
{
    int curr_sum = 0;
    for(int i =0; i<k; i++)
    {
        curr_sum += v[i];
    }
    int max_sum = curr_sum;
    for(int i=k; i < v.size(); i++)
    {
        curr_sum += (v[i] - v[i-k]);
        max_sum = max(max_sum, curr_sum);

    }
    return max_sum;
}


int main()
{
    vector<int> v;
    int n;
    cin >>n;           // Size of vector v
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);

    }
    int k;
    cin>>k;
    
    cout<< findmaxsum(v, k);
    
    return 0;
}
