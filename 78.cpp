class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> answer;
        int n = nums.size();
        for (int i = 0 ; i<pow(2,n);i++)
        {
            vector <int> temp;
            for (int j = 0 ; j<n ; j++)
            {
                if ((1 << j) & i )
                {
                    temp.push_back(nums[j]);
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }
};
