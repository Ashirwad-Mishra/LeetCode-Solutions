class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int minI = -1;
        int maxI = -1;
        int strt = -1;

        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] < minK || nums[i] > maxK) strt = i;
            if (nums[i] == minK) minI = i;
            if (nums[i] == maxK) maxI = i;

            int valid = max(0 , min(minI , maxI) - strt);
            ans += valid;
        }
        return ans;
    }
};
