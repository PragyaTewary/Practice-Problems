#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<climits>
using namespace std;

//We are given a set of activities. Every activity is represented as a pair.
//The first element of the pair is starting time and the second element of the pair is the end time.
//We have a single machine which can do only one task at a time.
//We need to maximise the number of activities that we can perform on the single machine.

bool myCmp(pair <int, int> a, pair <int, int> b)
{
    return(a.second < b.second);
}

int maxActivities(pair <int, int> arr[], int n)
{
    sort(arr, arr+n, myCmp);
    int res=1;
    int prev= 0;
    for(int curr=1; curr<n; curr++)
    {
        if(arr[prev].second <= arr[curr].first)
        {
            res++;
            prev= curr;

        }
    }
    return res;

}
int main()
{
    pair <int, int> arr[] = {make_pair(1, 3), make_pair(10, 11), make_pair(3, 8), make_pair(2, 4)};

	int n = 4;

	cout<<maxActivities(arr, n); 

	return 0;

}
