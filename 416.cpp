class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if (sum % 2 != 0) return false;
        vector <bool> dp(sum/2 + 1 , false);
        dp[0] = true;
        for (int i : nums)
        {
            for (int j = sum/2 ; j >= i ; --j)
            {
                dp[j] = dp[j] || dp[j-i];
            }
        }
        return dp[sum/2];
    }
};
