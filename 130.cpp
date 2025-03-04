class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int , int>>q;
        for (int i = 0 ; i < board.size() ; i++)
        {
            for (int j = 0 ; j < board[0].size() ; j++)
            {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size()-1 || j == board[0].size() - 1)) 
                {
                    q.push({i,j});
                    board[i][j] = 'T';
                }
            }
        }
        vector <int> dx = {0 , 0 , -1 , 1};
        vector <int> dy = {-1 , 1 , 0 , 0};
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0 ; k < 4 ; k++)
            {
                int row = x + dx[k];
                int col = y + dy[k];
                if (row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && board[row][col] == 'O')
                {
                    q.push({row,col});
                    board[row][col] = 'T';
                }
            }
        }
        for (int i = 0 ; i < board.size() ; i++)
        {
            for (int j = 0 ; j < board[0].size() ; j++)
            {
                if (board[i][j] == 'T') 
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
