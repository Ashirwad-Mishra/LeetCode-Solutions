class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map <int , int> mp;
        for (auto &i : answers) mp[i]++;

        int ans = 0;
        for (auto &p : mp)
        {
            int x = p.first;
            int y = p.second;

            while (y > 0)
            {
                ans += (x + 1);
                y -=(x + 1);
            }
        }
        return ans;
    }
};
