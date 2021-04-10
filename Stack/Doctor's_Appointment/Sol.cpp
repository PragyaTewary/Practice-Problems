#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int T; cin>>T;
	while(T--)
	{
	    int n,patientNo; 
	    cin>>n;
	    int missedNo= 0;
	    
	    stack<int> s;
	    vector<bool> v(n+1);
	    while(n--)
	    {
	        cin>>patientNo;
	        if(patientNo >missedNo)
	        {
	            cout<<patientNo<<" ";
	            missedNo++;

	            while(patientNo >missedNo)
	           {
	               s.push(missedNo++);
	           }
	        }
	        
	        v[patientNo] =1;
	        while(s.size() != 0 && v[s.top()])
	        {
	            cout<<s.top()<<" ";
	            s.pop();
	        }
	    }
	    while(s.empty() == false )
	    {
	        cout<<s.top()<<" ";
	        s.pop();
	        
	    }
	    cout<<endl;
	}
	return 0;
}
