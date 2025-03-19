class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0 , j = 1 , k = 2; k < nums.size() ; i++ , j++, k++)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1;
                nums[j] = nums[j] == 1 ? 0 : 1;
                nums[k] = nums[k] == 1 ? 0 : 1;
                ans++;
            }
        }
        if (accumulate(nums.begin() , nums.end() , 0) == nums.size()) return ans;
        return -1;
    }
};
