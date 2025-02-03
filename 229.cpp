class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map <int , int> memo;
        for (auto i : nums) memo[i]++;
        vector <int> ans;
        int n = nums.size();
        for (auto &p : memo)
        {
            if (p.second > n / 3) ans.push_back(p.first);
        }
        return ans;
    }
};
