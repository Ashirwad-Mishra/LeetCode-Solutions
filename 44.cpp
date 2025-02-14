class Solution {
private:
    bool solve(string &s, string &p, int i, int j, int n, int m, vector<vector<int>> &memo)
    {
        if (memo[i][j] != -1) return memo[i][j];  
        if (i == n && j == m) return memo[i][j] = true;  
        if (j == m) return memo[i][j] = false; 

        bool ans = false;

        if (p[j] == '*') 
        {
            ans = solve(s, p, i, j + 1, n, m, memo) || (i < n && solve(s, p, i + 1, j, n, m, memo));
        } 
        else if (i < n && (s[i] == p[j] || p[j] == '?')) 
        {
            ans = solve(s, p, i + 1, j + 1, n, m, memo);
        } 

        return memo[i][j] = ans;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));  
        return solve(s, p, 0, 0, s.length(), p.length(), memo);
    }
};
