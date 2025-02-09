class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>>ans;
        vector <int> temp = nums;
        while (true)
        {
            ans.push_back(nums);
            next_permutation(nums.begin(),nums.end());
            if (temp == nums) break;
        }
        return ans;
    }
};
