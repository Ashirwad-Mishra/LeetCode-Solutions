class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int lower = 0;
        unordered_set<int> un(nums.begin() , nums.end());
        if (un.size() == 1) return *un.begin() > k ? 1 : *un.begin() == k ? 0 : -1;
        for (auto &i : un)
        {
            if ( i > k) ans++;
            if (i < k) return -1;
        }
        return ans == 0 ? -1 : ans;
    }
};
