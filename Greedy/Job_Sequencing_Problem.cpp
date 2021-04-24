#include<iostream>
#include<algorithm>
using namespace std;


//Given an array of jobs of size n where every job has a deadline and 
//associated profit if the job is finished before the deadline.
//It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. 
//Time starts with 0.
//How to maximize total profit if only one job can be scheduled at a time.





struct Job
{
    int deadline; //Deadline of Job
    int profit;   //Profit if job is over before or on dealine

};

// This function is used for sorting all
// jobs according to profit
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

int FindMaxProfit(Job arr[], int n)
{
    sort(arr, arr+n, comparison);  // Sort all jobs according to decreasing order of profit
    int max_profit = 0;
    bool slot[n];         // To keep track of free time slots

    for(int i=0; i<n; i++)
        slot[i] = false ; 
    
    for(int i=0; i<n; i++)
    {
        for(int j = min(n, arr[i].deadline)-1; j>=0; j--)
        {
            if(slot[j] == false)
            {
                max_profit += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    return max_profit;

}

int main()
{
    Job arr[] = { {2, 100}, {1, 19}, {2, 27},
                {1, 25}, {3, 15}};
                
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Maximum profit of job : "<<FindMaxProfit(arr, n);
    
    return 0;
}