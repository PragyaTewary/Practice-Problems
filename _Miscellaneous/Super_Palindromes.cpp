#include<bits/stdc++.h>
using namespace std;

//A positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
//Given two positive integers left and right represented as strings, 
//return the number of super-palindromes integers in the inclusive range [left, right].
//Note that here the range of left and right can be :  1 <= left <= right <= 10^18.


 
// check if a number is a palindrome
bool ispalindrome(int x)
{
    int ans = 0;
    int temp = x;
    while (temp > 0)
    {
        ans = 10 * ans + temp % 10;
        temp = temp / 10;
    }
    return ans == x;
}
  
// Function to return required count of palindromes

int SuperPalindromes(int L, int R)
{
    // Range [L, R]
  
    // Upper limit
    int LIMIT = 100000;
  
    int ans = 0;
  
    // count odd length palindromes
    for (int i = 0 ;i < LIMIT; i++)
    {
        string s = to_string(i);         // if s = '1234'
        string rs = s.substr(0, s.size() - 1);
        
        reverse(rs.begin(), rs.end());
  
        string p = s + rs;               // then, p = '1234321'
        int p_sq = stoi(p)*stoi(p);
        if (p_sq > R)
            break;

        if (p_sq >= L && ispalindrome(p_sq))
        {
            ans = ans + 1;
        }
    }
  
    // count even length palindromes
    for (int i = 0 ;i < LIMIT; i++)
    {
        string s = to_string(i);        // if s = '1234'
        string rs = s;
        
        reverse(rs.begin(), rs.end());
        
        string p = s + rs;             // then, p = '12344321'
        int p_sq = stoi(p)*stoi(p);
        if (p_sq > R)
            break;
        if (p_sq >= L && ispalindrome(p_sq))
        {
            ans = ans + 1;
        }    
    }
  
    // Return count of super-palindromes
    return ans;
}


int main()
{
    string left = "4";
    string right = "1000";
      
    // function call to get required answer
    printf("%d\n", SuperPalindromes(stoi(left), stoi(right)));
    return 0;
} 
