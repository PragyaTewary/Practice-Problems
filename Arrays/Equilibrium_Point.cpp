 #include<iostream>
 using namespace std;


// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
 
 
 int equilibriumPoint(long long arr[], int n) {
    
        if(n==1)
            return 1;
        int prefix_sum = 0;
        int suffix_sum = 0;
        long long sums =0;
        for(int i=0; i<n; i++)
        {
            sums += arr[i];
        }
        for(int i=1; i<n; i++)
        {
            prefix_sum += arr[i-1];
            suffix_sum  = sums - arr[i] - prefix_sum;
            
            if(prefix_sum == suffix_sum)
            {
                return (i+1);
            }
            
        }
        return -1;
    }


int main() 
{

    long long t;
    
    //taking testcases
    cin >> t;
    while (t--) 
    {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        

        //calling equilibriumPoint() function
        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}