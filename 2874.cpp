class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector <int> leftMax(nums.size());
        leftMax[0] = nums[0];
        vector <int> rightMax(nums.size());
        rightMax[nums.size() - 1] = nums.back();
        for (int i = 1 ; i < nums.size() ; i++)
        {
            leftMax[i] = max(nums[i] , leftMax[i-1]);
        }
        for (int i = nums.size() - 2 ; i >= 0 ; i--)
        {
            rightMax[i] = max(nums[i] , rightMax[i+1]);
        }

        long long ans = 0;
        for (int i = 1 ; i < nums.size() -1; i++)
        {
            ans = max(ans , static_cast<long long>(leftMax[i-1] - nums[i])*rightMax[i+1]);
        }
        return ans;
    }
};
