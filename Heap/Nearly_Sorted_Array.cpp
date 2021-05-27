#include <bits//stdc++.h>
using namespace std;

// Given an array of n elements, where each element is at most k away from its target position.
// The task is to print array in sorted form.
// Input:
// First line consists of t test cases. 
// First line of every test case consists of two integers n and k, 
// denoting number of elements in array and at most k positions away from its target position respectively.
// Second line of every test case consists of elements of array.
// Output:
// Single line output to print the sorted array.


vector<int> KsortedArray(int* arr, int n, int k)
{
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;  // Created Min Heap
    for(int i=0; i<=k && i !=n ; i++)
    {
        pq.push(arr[i]);
    }
    for(int i=0, j=k+1; i<n-k && j<n; i++, j++)
    {
        v.push_back(pq.top());
        pq.pop();
        pq.push(arr[j]);
    }
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    
    return v;
}



int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    scanf("%d%d", &n, &k);
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    vector<int> v = KsortedArray(arr, n, k);
	    for(int i=0; i<n; i++)
	    {
	        printf("%d ", v[i]);
	    }
	    cout<<endl;
	}
	return 0;
}