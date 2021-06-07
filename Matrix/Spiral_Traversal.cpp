#include <bits/stdc++.h>
using namespace std;

// Given a matrix of size r*c. Traverse the matrix in spiral form.
// Example:
// Input: r = 4, c = 4
/* matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/


vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    int top=0, left = 0, right = c-1, bottom = r-1;
    vector<int> ls;
    while(top<= bottom && left <= right)
    {
        for(int i=left; i<=right; i++)
        {
            ls.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++)
        {
            ls.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom)
        {
            for(int i=right; i>= left; i--)
            {
                ls.push_back(matrix[bottom][i]);
                
            }
            bottom--;
        }
        if(left <= right)
        {
            for(int i=bottom; i>= top; i--)
            {
                ls.push_back(matrix[i][left]);
                
            }
            left++;
        }
    }
    return ls;
}


int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int> > matrix(r); 

    for(int i=0; i<r; i++)
    {
        matrix[i].assign(c, 0);
        for( int j=0; j<c; j++)
        {
            cin>>matrix[i][j];
        }
    }

    vector<int> result = spirallyTraverse(matrix, r, c);
    for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
    cout<<endl;
    
}