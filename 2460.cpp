class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i < n - 1 ; i++)
        {
            if (nums[i]==nums[i+1]) 
            {
                nums[i]*=2;
                nums[i+1] = 0;
            }
        }
        int zeroes = 0;
        for (auto i : nums) 
        {
            if (i == 0) zeroes ++;
        }
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        while (zeroes--) nums.push_back(0);
        return nums;
    }
};
