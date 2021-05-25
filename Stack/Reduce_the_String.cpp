#include <bits/stdc++.h>
using namespace std;


// Given a string s and an integer k, the task is to reduce the string by applying the following operation:
// Choose a group of k consecutive identical characters and remove them.
// The operation can be performed any number of times until it is no longer possible.




string Reduced_String(int k,string s)
{
    stack<pair<char, int>> st;
    string final_result = "";
    if(k==1)
        return final_result;
    int count=0;
    int n = s.length();
    for(int i=0; i<n; i++)
    {
        if(!st.empty() && st.top().first == s[i])
        {
            count = st.top().second + 1;
            st.push(make_pair(s[i], count));
            if(count == k)
            {
                while(count--)
                {
                    st.pop();
                }
            }
            
        }
        else
        {
            count=1;
            st.push(make_pair(s[i], count));
        }
    }
    
    while(st.empty() == false)
    {
        final_result += st.top().first;
        st.pop();
        
    }
    reverse(final_result.begin(), final_result.end());
    return final_result;

}

int main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;

    cout << Reduced_String(k,s) << "\n";
    return 0;
}