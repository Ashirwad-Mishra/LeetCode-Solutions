class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        vector <int> minLeft(n);
        vector <int>minRight(n);

        minLeft[0] = nums[0];
        minRight[n-1] = nums.back();

        for (int i = 1 ; i < n ; i++)
        {
            minLeft[i] = min(minLeft[i-1] , nums[i]);
        }
        for (int i = n - 2 ; i >= 0 ; i--)
        {
            minRight[i] = min(minRight[i+1] , nums[i]);
        }

        int ans = INT_MAX;

        for (int i = 1 ; i < n - 1 ; i++)
        {
            if (nums[i] > minLeft[i-1] && nums[i] > minRight[i+1])
            {
                ans = min(ans , nums[i] + minLeft[i-1] + minRight[i+1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
