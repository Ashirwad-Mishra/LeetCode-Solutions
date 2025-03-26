class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> help;
        for (auto &v : grid)
        {
            help.insert(help.end() , v.begin() , v.end());
        }
        sort(help.begin() , help.end());
        int median = help[help.size()/2];
        int ans = 0;
        for (auto &i : help)
        {
            int diff = abs(i - median);
            if (diff % x != 0) return -1;
            ans += diff / x;
        }
        return ans;
    }
};
