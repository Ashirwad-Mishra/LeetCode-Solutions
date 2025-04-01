// TC : exponential
// TLE
class Solution {
    int LTR(vector<int>& nums ,int idx , int point)
    {
        if (idx >= nums.size() - 1) return point;
        int taken = LTR(nums , idx + 2 , point + nums[idx]);
        int ignored = LTR(nums , idx + 1 , point);
        return max(taken , ignored);
    }

    int RTL(vector<int>& nums ,int idx , int point)
    {
        if (idx == 1) return point + nums[idx];
        if (idx <= 0) return point;
        int taken = RTL(nums , idx - 2 , point + nums[idx]);
        int ignored = RTL(nums , idx - 1 , point);
        return max(taken , ignored);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(LTR(nums , 0 , 0) , RTL(nums , nums.size() - 1 , 0));
    }
};

// TC : O(n)
// SC : O(n)
class Solution {
    int LTR(vector<int>& nums ,int idx , vector <vector <int>>&DP)
    {
        if (idx >= nums.size() - 1) return 0;
        if (DP[idx][0] != -1) return DP[idx][0];
        int taken = nums[idx] + LTR(nums , idx + 2 , DP);
        int ignored = LTR(nums , idx + 1 , DP);
        return DP[idx][0] = max(taken , ignored);
    }

    int RTL(vector<int>& nums ,int idx  , vector <vector <int>>&DP)
    {
        if (idx == 1) return nums[idx];
        if (idx <= 0) return 0;
        if (DP[idx][1] != -1) return DP[idx][1];
        int taken = nums[idx] + RTL(nums , idx - 2 , DP);
        int ignored = RTL(nums , idx - 1 , DP);
        DP[idx][1] = max(taken , ignored);
        return DP[idx][1];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector <vector <int>>DP(nums.size() , vector <int>(2 , -1));
        return max(LTR(nums , 0 , DP) , RTL(nums , nums.size() - 1 , DP));
    }
};
