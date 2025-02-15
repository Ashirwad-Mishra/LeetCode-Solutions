class Solution {
    int m;
    vector<vector<vector<int>>> memo;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2)
    {
        int c2 = r1 + c1 - r2; // Calculate c2 using (r1 + c1 = r2 + c2)

        if (r1 >= m || c1 >= m || r2 >= m || c2 >= m || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == m - 1 && c1 == m - 1)
            return grid[r1][c1];

        if (memo[r1][c1][r2] != -1)
            return memo[r1][c1][r2];

        int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] : (grid[r1][c1] + grid[r2][c2]);

        // Try all possible moves
        int f1 = solve(grid, r1 + 1, c1, r2 + 1); // Both move down
        int f2 = solve(grid, r1 + 1, c1, r2);     // First down, second right
        int f3 = solve(grid, r1, c1 + 1, r2 + 1); // First right, second down
        int f4 = solve(grid, r1, c1 + 1, r2);     // Both move right

        int maxCherries = max({f1, f2, f3, f4});
        if (maxCherries == INT_MIN) return memo[r1][c1][r2] = INT_MIN;

        return memo[r1][c1][r2] = cherries + maxCherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        memo.assign(m, vector<vector<int>>(m, vector<int>(m, -1)));

        int result = solve(grid, 0, 0, 0);
        return (result == INT_MIN) ? 0 : result;
    }
};
