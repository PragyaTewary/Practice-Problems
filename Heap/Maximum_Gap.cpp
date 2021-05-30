#include<bits/stdc++.h>
using namespace std;


// Given an integer array nums, return the maximum difference between two successive elements in its sorted form.
// If the array contains less than two elements, return 0.
// You must write an algorithm that runs in linear time and uses linear extra space.



int maximumGap(vector<int>& nums) 
{
    int n = nums.size();
    if(n<2)
    {
        return 0; 
    }
    priority_queue<int> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(nums[i]);
    }
    int max_diff = 0;
    while(!pq.empty())
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        max_diff = max((a-b), max_diff);
    }
    return max_diff;
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout << maximumGap(nums) ; 
}