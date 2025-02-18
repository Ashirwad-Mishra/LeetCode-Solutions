class Solution {
    void DFS(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean, int prevHeight) 
    {
        int m = heights.size(), n = heights[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || ocean[i][j] || heights[i][j] < prevHeight) 
            return;

        ocean[i][j] = true;

        DFS(i + 1, j, heights, ocean, heights[i][j]);
        DFS(i - 1, j, heights, ocean, heights[i][j]);
        DFS(i, j + 1, heights, ocean, heights[i][j]);
        DFS(i, j - 1, heights, ocean, heights[i][j]);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) 
        {
            DFS(i, 0, heights, pacific, heights[i][0]); // Pacific border
            DFS(i, n - 1, heights, atlantic, heights[i][n - 1]); // Atlantic border
        }

        for (int j = 0; j < n; j++) 
        {
            DFS(0, j, heights, pacific, heights[0][j]); // Pacific border
            DFS(m - 1, j, heights, atlantic, heights[m - 1][j]); // Atlantic border
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (pacific[i][j] && atlantic[i][j]) 
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
