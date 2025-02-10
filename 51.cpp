// Approach 1 :-


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

// Aproach 2:- 
class Solution {
private:
    void solve(vector <vector <string>> &ans , int row , int n , vector <string> &board , unordered_set <int> &cols , unordered_set <int> &D , unordered_set <int> &AD)
    {
        if (row >= n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0 ; col < n ; col++)
        {
            int DC = row + col;
            int ADC = row - col;
            if (cols.find(col) != cols.end() || D.find(DC) != D.end() || AD.find(ADC) != AD.end())
            {
                continue;
            }
            cols.insert(col);
            D.insert(DC);
            AD.insert(ADC);
            board[row][col] = 'Q';
            solve (ans , row + 1, n , board , cols , D , AD);
            board[row][col] = '.';
            cols.erase(col);
            D.erase(DC);
            AD.erase(ADC);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;
        vector <string> board(n , string(n , '.'));
        unordered_set <int> cols;
        unordered_set <int> D;
        unordered_set <int> AD;
        solve (ans , 0 , n , board , cols , D , AD);
        return ans;
    }
};
// Approach 3 :- Best Approach
class Solution {
private:
    void solve(vector <vector <string>> &ans , int row , int n , vector <string> &board , vector <bool> &cols , vector <bool> &D , vector <bool> &AD)
    {
        if (row >= n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0 ; col < n ; col++)
        {
            int DC = row + col;
            int ADC = row - col + n - 1;
            if (cols[col] || D[DC] || AD[ADC])
            {
                continue;
            }
            cols[col] = true;
            D[DC] = true;
            AD[ADC] = true;
            board[row][col] = 'Q';
            solve (ans , row + 1, n , board , cols , D , AD);
            board[row][col] = '.';
            cols[col] = false;
            D[DC] = false;
            AD[ADC] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;
        vector <string> board(n , string(n , '.'));
        vector <bool> cols(n, false);
        vector <bool> D(3*n, false);
        vector <bool> AD(3*n, false);
        solve (ans , 0 , n , board , cols , D , AD);
        return ans;
    }
};
