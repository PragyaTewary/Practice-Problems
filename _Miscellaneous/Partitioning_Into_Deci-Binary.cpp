#include<bits//stdc++.h>
using namespace std;

// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
// For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
// Given a string str that represents a positive decimal integer, 
// return the minimum number of positive deci-binary numbers needed so that they sum up to n.
// Eg :
// Input: n = "32"
// Output: 3
// Explanation: 10 + 11 + 11 = 32


int minPartitions(string str) 
{
    int maxno = 0;
    for(auto ch : str)
    {
        int no = ch - '0';
        maxno = max(no, maxno);
    }
    return maxno;
}

int main()
{
    string n;
    cout<< "Enter the string : "<<endl;
    cin>>n;
    cout<< "Minimum number of positive deci-binary numbers needed so that they sum up to n : "<<minPartitions(n);
}