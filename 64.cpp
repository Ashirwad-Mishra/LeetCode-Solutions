class Solution {
public:
    int helper(vector<vector<int>>& grid, map<pair<int, int>, int>& memo, int m, int n) {
        if (m == 0 && n == 0) 
            return grid[m][n];
        
        pair<int, int> p = make_pair(m, n);

        if (memo.find(p) != memo.end()) 
            return memo[p];

        int minPath = INT_MAX;

        if (m > 0) 
            minPath = min(minPath, helper(grid, memo, m - 1, n));

        if (n > 0) 
            minPath = min(minPath, helper(grid, memo, m, n - 1));

        memo[p] = minPath + grid[m][n];

        return memo[p];
    }

    int minPathSum(vector<vector<int>>& grid) {
        map<pair<int, int>, int> memo;
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;

        return helper(grid, memo, m, n);
    }
};
