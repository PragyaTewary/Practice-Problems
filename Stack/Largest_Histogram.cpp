#include <iostream>
#include<stack>
using namespace std;

//We are given an array. Every element represents heights of bar in histogram. Width for all bar is same. 
//We need to find out largest rectangular area in histogram.  
int main() {
	int T; cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int *arr = new int[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    
	    //To find next smaller element index  on the right- 
	    int *rb = new int[n]; //For Right Boundary
	    stack<int> s;
	    s.push(n-1);
	    rb[n-1]=n;
	    for(int i=n-2; i>=0; i--)
	    {
	        while(s.size() != 0 && arr[s.top()] >= arr[i])
	        {
	            s.pop();
	        }
	        if(s.size()==0)
	                rb[i]=n;
	        else{
	            rb[i]=s.top();
	        }
	        s.push(i);
	    }
	    
	    //To find next smaller element index  on the left-
	    int *lb = new int[n];   //For Left Boundary
	    stack<int> s1;
	    s1.push(0);
	    lb[0]=-1;
	    for(int i=1; i<n; i++)
	    {
	        while(s1.size() != 0 && arr[s1.top()] >= arr[i])
	        {
	            s1.pop();
	        }
	        if(s1.size()==0)
	                lb[i]=-1;
	        else{
	            lb[i]=s1.top();
	        }
	        s1.push(i);
	    }
	    //Area
	    int MaxArea = 0;
	    for(int i=0; i<n; i++)
	    {
	        int width = rb[i] - lb[i]-1;
	        int Area = arr[i]*width;
	        if(Area>MaxArea)
	               MaxArea = Area;
	    }
	    cout<<MaxArea<<'\n';
	}
	return 0;
}
