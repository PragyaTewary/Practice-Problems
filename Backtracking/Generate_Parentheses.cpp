#include<bits/stdc++.h>
using namespace std;


// Given an integer N representing the number of pairs of parentheses,
// the task is to generate all combinations of well-formed(balanced) parentheses.


vector<string> v;
void getParenthesis(int pos,int n, int open, int close)
{
    static char str[100];
    if(close==n)
    {
        v.push_back(str);
        return;
        
    }
    else
    {
        if(open > close)
        {
            str[pos] = ')';
            getParenthesis(pos+1, n, open, close+1);
        }
        if(open < n)
        {
            str[pos] = '(';
            getParenthesis(pos+1, n, open+1, close);
        }
        
    }
        
}

vector<string> AllParenthesis(int n) 
{
    if(n==0)
    {
        string str ="";
        v.push_back(str);
    }
    else
        getParenthesis(0,n,0,0);
    return v;
}

int main() 
{ 
	
    int n;
    cin>>n;

    vector<string> result = AllParenthesis(n); 
    sort(result.begin(),result.end());
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<"\n";

	return 0; 
} 

