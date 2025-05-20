class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> vec(nums.size() + 1, 0);
        for (int i = 0 ; i < queries.size() ; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            vec[l] += 1;
            vec[r] -= 1;
        }

        for (int i = 1 ; i < vec.size() ; i++)
        {
            vec[i] += vec[i-1];
        }

        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] >= vec[i]) nums[i] -= vec[i];
            else nums[i] = 0;
            if (nums[i]) return false;
        }
        return true;
    }
};
