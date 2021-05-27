#include<bits//stdc++.h>
using namespace std;

// Given an input stream arr[] of n integers.
// Find the Kth largest element at any point of time for each element in the stream.
// and if the Kth element doesn't exist, return -1.


vector<int> kthLargest(int k, int arr[], int n) 
{
    vector<int> v;
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0; i<k; i++)
    {
        pq.push(arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(i < k-1)
        {
            v.push_back(-1);
        }
        else
        {
            if(i==k-1)
            {
                //cout<<pq.top();
                v.push_back(pq.top());
            }
            else if(arr[i] < pq.top())
            {
                v.push_back(pq.top());
            }
            else
            {
                pq.pop();
                pq.push(arr[i]);
                v.push_back(pq.top());
            }
        }
    }
    return v;
}


int main()
{
    int k,n;
    cin>>k>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> v = kthLargest(k,arr,n);
    
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}