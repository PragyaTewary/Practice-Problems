#include <bits/stdc++.h>
using namespace std;


// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle.
// Each solution contains distinct board configurations of the n-queens’ placement,
// where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes 
// that the ith-column queen is placed in the row with that number. 



// Program to solve N Quuens problem using Branch and Bound Algorithm

vector<vector<int>> result;
    
void getNQueen(vector<vector<bool>>& chess, int row, bool*cols, bool* ndiag, bool* rdiag)
{
    if(row == chess.size())
    {
        vector<int> qsf;
        for(int i=0; i<chess.size(); i++)
        {
            for(int j=0; j<chess[0].size(); j++)
            
            {
                if(chess[i][j] == 1)
                    qsf.push_back(j+1);
            }
        }
        
        result.push_back(qsf);
        
        return;
    }
    
    for(int col=0; col < chess[0].size(); col++)
    {
        if(cols[col]==false && ndiag[row+col] == false && rdiag[row-col+chess.size()-1] == false)
        {
            chess[row][col] = true;
            cols[col] = true;
            ndiag[row+col] = true;
            rdiag[row-col+chess.size()-1] = true;
            
            getNQueen(chess, row+1, cols, ndiag, rdiag);
            
            chess[row][col] = false;
            cols[col]=false;
            ndiag[row+col] = false;
            rdiag[row-col+chess.size()-1] = false;
        }
    }
}


vector<vector<int>> nQueen(int n) 
{
    vector<vector<bool>> chess(n, vector<bool>(n));
    
    bool* cols = new bool[n];
    bool* ndiag = new bool[2*n-1];
    bool* rdiag = new bool[2*n-1];
    for(int i=0; i<n; i++)
    {
        cols[i] = false;
        
    }
    for(int j=0; j<2*n-1; j++)
    {
        ndiag[j] = false;
        
    }
    for(int j=0; j<2*n-1; j++)
    {
        rdiag[j] = false;
        
    }
    getNQueen(chess, 0, cols, ndiag, rdiag);
    return result;
}


int main()
{
    // Board size
    int n;
    cin>>n;

    result.clear();
    nQueen(n);
    sort(result.begin(),result.end());
    for (auto ar : result) {
        cout << "[";
        for (auto it : ar)
            cout << it << " ";
        cout << "]";
    }
    return 0;
}
