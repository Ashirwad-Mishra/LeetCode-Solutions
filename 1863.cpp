class Solution {
    int ans = 0;
    void helper(int idx , vector<int>& nums , int currXor)
    {
        if (idx >= nums.size()) 
        {
            ans += currXor;
            return;
        }

        helper(idx + 1 , nums , currXor ^ nums[idx]);
        helper(idx + 1 , nums , currXor);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        helper(0 , nums , 0);
        return ans;
    }
};
