#include<iostream>
#include<vector>
#include<string>
using namespace std;

//You are given a number n, the size of a chess board.
//You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
//Note - Queens kill at distance in all 8 directions.
//Calculate and print all safe configurations of n-queens.
//Answer is in the format "Row number - Column number"

bool IsItSafePlaceForTheQueen(vector<vector<int>>& chess, int row, int col)
{
    int n = chess.size();

    //For verticle check:
    for(int i= row-1, j= col; i>=0; i--)
    {
        if(chess[i][j] == 1)
            return false;
    }

    //For diagonal check on left side:
    for(int i= row-1, j= col-1; i>=0 && j>=0; i--, j--)
    {
        if(chess[i][j] == 1)
            return false;
    }
    //For diagonal check on right side:
    for(int i= row-1, j= col+1; i>=0 && j<n; i--, j++)
    {
        if(chess[i][j] == 1)
            return false;
    }

    return true;

}

void printNQueens(vector<vector<int>>& chess, string qsf, int row)
{
    int n = chess.size();
    if(row == n)
    {
        cout<<qsf<<"."<<endl;
        return;
    }
    for(int col= 0; col< n; col++)
    {
        if(IsItSafePlaceForTheQueen(chess, row, col)== true)
        {
            chess[row][col]=1;
            printNQueens(chess, qsf+ to_string(row)+ "-"+ to_string(col)+ ", " , row+1);
            chess[row][col]= 0;
        }
    }

}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            board[i][j] = 0;
        }
    }
    printNQueens(board, "", 0);

}