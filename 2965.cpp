class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <int> ans(n*n + 1);
        for (auto &v : grid)
        {
            for (auto i : v)
            {
                ans[i]++;
            }
        }
        vector <int> ret(2);
        for (int i = 1 ; i < ans.size() ; i++)
        {
            if (ans[i] == 2) ret[0] = i;
            else if (ans[i] == 0) ret[1] = i;
        }
        return ret;
    }
};
