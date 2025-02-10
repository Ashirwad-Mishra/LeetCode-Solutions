class Solution {
private:
    bool isValid(vector <string> &board , int row , int col , int n)
    {
        for (int i = 0 ; i < row ; i++)
        {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1 , j = col - 1 ; i >= 0 && j >= 0 ; i-- , j--)
        {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1 , j = col + 1 ; i >= 0 && j < n  ; i-- , j++)
        {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector <vector <string>> &ans , int row , int n , vector <string> &board)
    {
        if (row >= n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0 ; col < n ; col++)
        {
            if (isValid(board , row , col , n))
            {
                board[row][col] = 'Q';
                solve (ans , row + 1, n , board);
                board[row][col] = '.';
            }
            
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;
        vector <string> board(n , string(n , '.'));
        solve (ans , 0 , n , board);
        return ans;
    }
};
