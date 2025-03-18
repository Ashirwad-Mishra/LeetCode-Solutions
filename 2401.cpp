class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int le = 0; 
        int ans = 1; 
        int bitwise_or = 0; 
        int n = nums.size();

        for (int i = 0; i < n; i++) 
        {
            while ((bitwise_or & nums[i]) != 0) 
            { 
                bitwise_or ^= nums[le];
                le++;
            }
            bitwise_or |= nums[i];
            ans = max(ans, i - le + 1);
        }
        
        return ans;
    }
};
