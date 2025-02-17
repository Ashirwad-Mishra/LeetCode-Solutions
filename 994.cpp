class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q; 
        int fresh = 0;
        int time = 0;
        for (int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        vector <pair<int , int>> directions = {{1 , 0} , {-1 , 0} , {0 , -1} , {0 , 1}};
        while (!q.empty() && fresh > 0)
        {
            int size = q.size();
            time++;
            for (int i = 0 ; i < size ; i++)
            {
                auto [x , y] = q.front();
                q.pop();
                for (auto [dx , dy] : directions)
                {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2 ;
                        fresh--;
                        q.push({newX , newY});
                    }
                }
            }
        }
        return fresh == 0 ? time : -1;
    }
};
