class Solution {
    void DFS(int i , int j , vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1' ) return;
        grid[i][j] = '#';
        DFS(i + 1 , j , grid);
        DFS(i - 1 , j , grid);
        DFS(i , j + 1 , grid);
        DFS(i , j - 1 , grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        for (int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                if (grid[i][j] == '1')
                {
                    DFS( i , j , grid);
                    c++;
                } 

            }
        }
        return c;
    }
};
