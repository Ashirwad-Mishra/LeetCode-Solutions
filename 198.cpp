class Solution {
private: 
    int help(vector<int>& nums , int i , vector <int> &memo)
    {
        if (i >= nums.size() ) return 0;
        if (memo[i] != -1) return memo[i];
        return memo[i] =  max(help(nums , i + 1  , memo) , nums[i] + help(nums , i + 2 , memo));
    }
public:
    int rob(vector<int>& nums) {
        vector <int> memo (nums.size() , -1);
        return help(nums ,0 , memo);
    }
};
