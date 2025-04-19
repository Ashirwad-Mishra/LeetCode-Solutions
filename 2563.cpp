class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() , nums.end());
        long long ans = 0;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int lo = lower - nums[i];
            int hi = upper - nums[i];

            int left = lower_bound(nums.begin() + i + 1 , nums.end() , lo) - nums.begin();
            int right = upper_bound(nums.begin() + i+ 1 , nums.end() , hi ) - nums.begin();

            ans += right - left;
        }
        return ans;
    }
};
