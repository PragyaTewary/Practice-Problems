#include<iostream>
#include<string>
#include<vector>
using namespace std;

//You are given a number n and m, representing the number of rows and number of columns respectively.
//You are given n*m numbers, representing elements of 2d array maze. The numbers can be 1 or 0 only.
//You are standing in the top-left corner and have to reach the bottom-right corner. 
//Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right).
//You can only move to cells which have 0 value in them. 
//You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle).
//Print all paths that can be used to move from top-left to bottom-right.
//Note : If all four moves are available make moves in the order 't', 'l', 'd' and 'r'.



void floodfill(vector<vector<int>>& maze, int row, int col, string psf, vector<vector<bool>>& visited)
{
    int x= maze.size();
    int y=maze[0].size();

    if(row<0 || col<0 || row==x || col==y || maze[row][col]==1 || visited[row][col]==true)
        return;
    if(row==x-1 && col==y-1)
    {
        cout<<psf<<endl;
        return;
    }
    visited[row][col]=true;
    floodfill(maze, row-1, col, psf+"t", visited);
    floodfill(maze, row, col-1, psf+"l", visited);
    floodfill(maze, row+1, col, psf+"d", visited);
    floodfill(maze, row, col+1, psf+"r", visited);
    visited[row][col]=false;
}

int main(){
    int row=0,col=0,n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> maze(n,vector<int>(m));
    vector<vector<bool>> visited(n,vector<bool>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    floodfill(maze, row, col, "", visited);
    return 0; 
}