class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> memo;
        for (auto i : nums) memo[i]++;
        
        vector<pair<int, int>> vec(memo.begin(), memo.end());
        
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
        {
            return a.second > b.second;
        });
        
        vector<int> ans;
        for (int i = 0; i < k; i++) 
        {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};
