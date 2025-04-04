class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector <vector <int>>ans(2);

        map<int , int> hashMap;
        for (auto &v : matches)
        {
            hashMap[v[0]] += 0;
            hashMap[v[1]] += 1;
        }

        for (auto &p : hashMap)
        {
            if (p.second == 0) ans[0].push_back(p.first);
            else if (p.second == 1) ans[1].push_back(p.first);
        }
        return ans;
    }
};
