class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);         // Lengths
        vector<int> prev(n, -1);      // To reconstruct the path

        int maxIndex = 0;
        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) 
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) 
            {
                maxIndex = i;
            }
        }

        // Reconstruct the result
        vector<int> result;
        for (int i = maxIndex; i >= 0; i = prev[i]) 
        {
            result.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
