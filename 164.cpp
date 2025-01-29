class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        sort(nums.begin() , nums.end());
        int ans = nums[1] - nums[0];
        for (int i = 2 ; i < n ; i++)
        {
            if (ans < (nums[i] - nums[i-1])) ans = nums[i] - nums[i-1];
        }
        return ans;
    }
};
