class Solution {
    int nC2(int n) 
    {
        if (n < 2) return 0;
        return (n * (n - 1)) / 2;
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map <set <int> , int> mp;
        for (auto &v : dominoes) mp[{v[0] , v[1]}]++;
        int ans = 0;
        for (auto &p : mp)
        {
            ans += nC2(p.second);
        }
        return ans;
    }
};
