class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int le = 0;
        int sum = 0;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans,i -  le + 1);
                sum -= nums[le];
                le++;
            }
        }
        return (ans > nums.size()) ? 0 : ans ;
    }
};
