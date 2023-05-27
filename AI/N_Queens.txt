#include<bits/stdc++.h>
using namespace std;

void solve(int col,vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, 
            vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
    
        if(col == n) {
            ans.push_back(board);
            return;
        }


        for(int row=0; row<n; row++) {

            if(leftRow[row] == 0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + col-row] == 0) {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = 'X';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;

            }
        }
    
}


vector<vector<string>> solveNQueens(int n) {
    
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'X');
    for(int i=0; i<n; i++) {
        board[i] = s;
    }

    vector<int> leftRow(n,0), upperDiagonal(2*n-1, 0), lowerDaigonal(2*n-1, 0);

    solve(0, board, ans, leftRow, upperDiagonal, lowerDaigonal, n);
    return ans;

}


int main() {

    int n;
    cout<<"Enter N : "<<endl;
    cin>>n;

    vector<vector<string>> ans = solveNQueens(n);
    for(auto i : ans) {
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}