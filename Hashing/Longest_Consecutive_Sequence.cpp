#include <bits/stdc++.h>
using namespace std;


// Given an unsorted array of integers nums, return the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.


vector<int> longestConsecutive(vector<int>& nums) 
{
        
    unordered_map<int, bool> map;
    for(int i=0; i<nums.size(); i++)
    {
        map[nums[i]] = true;
    }
    
    for(int val : nums)
    {
        if(map.find(val-1) != map.end())
            map[val] = false;
    }
    
    
    int maxlen = 0;
    int maxstart = 0;
    
    for(int val : nums)
    {
        if(map[val] == true)
        {
            int templen = 1;
            int tempstart = val;
            while(map.find(tempstart + templen) != map.end())
            {
                templen++;
            }
            if(templen > maxlen)
            {
                maxlen = templen;
                maxstart = tempstart;
            }
        }
    }
    vector<int> res;
    
    for(int i=0; i < maxlen; i++)
    {
        res.push_back(maxstart);
        maxstart++;
        
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

    vector<int> ans = longestConsecutive(nums);

    for(int i = 0; i < ans.size(); i++)
    {
         cout << ans[i] <<" ";
    }
	return 0;
}