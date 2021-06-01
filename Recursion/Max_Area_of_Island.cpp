#include<bits/stdc++.h>
#include<vector>
using namespace std;

// You are given an m x n binary matrix grid.
// An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical).
// You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0


int CurrentArea(vector<vector<int>>& grid, int row, int col)
{
    if(row<0 || col <0 || row==grid.size() || col==grid[0].size() || grid[row][col] ==0 )
        return 0;
    grid[row][col] = 0;
    int up = CurrentArea(grid, row-1, col);
    int down = CurrentArea(grid, row+1, col);
    int left = CurrentArea(grid, row, col-1);
    int right = CurrentArea(grid, row, col+1);
    
    int totalArea = 1 + up + down + left + right;
    return totalArea;
}
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    int MaxArea = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == 1)
            {
                MaxArea = max(MaxArea, CurrentArea(grid, i, j));
            }
        }
    }
    return MaxArea;
}

int main()
{
    int m,n;
    cin>>m>>n; 
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout<<endl;
    }

    cout << maxAreaOfIsland(grid);
}