class Solution {
public:
    void helper(int i , int target , vector<int> &A , vector <vector<int>>&ans , vector <int> &memo)
    {
        if (i == A.size())
        {
            if (target == 0)
            {
                ans.push_back(memo);
            }
            return;
        }
        if (A[i] <= target)
        {
            memo.push_back(A[i]);
            helper(i,target - A[i],A,ans,memo);
            memo.pop_back();
        }
        helper(i+1 , target , A , ans , memo);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector <int>> ans;
        vector <int> memo;
        helper(0,target,candidates,ans,memo);
        return ans;
    }
};
