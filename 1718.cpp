class Solution {
    bool solve(int idx, int n, vector<int> &ans, vector<bool> &isUsed) {
        if (idx >= ans.size()) 
        {
            return true;
        }
        if (ans[idx] != -1) 
        {
            return solve(idx + 1, n, ans, isUsed); // Added return statement
        }
        for (int i = n; i >= 1; i--) 
        {
            if (isUsed[i]) 
            {
                continue;
            }
            isUsed[i] = true;
            ans[idx] = i;
            if (i == 1) 
            {
                if (solve(idx + 1, n, ans, isUsed)) return true;
            } 
            else 
            {
                int j = i + idx; // Use i instead of ans[idx]
                if (j < ans.size() && ans[j] == -1) 
                {
                    ans[j] = i;
                    if (solve(idx + 1, n, ans, isUsed)) return true;
                    ans[j] = -1; // Backtrack
                }
            }
            isUsed[i] = false;
            ans[idx] = -1;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) 
    {
        vector<int> ans(2 * n - 1, -1);
        vector<bool> isUsed(n + 1, false);
        solve(0, n, ans, isUsed);
        return ans;
    }
};
