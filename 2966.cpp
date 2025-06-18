class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        vector <vector <int>>ans;
        for (int i = 0 ; i < nums.size() ; i+=3)
        {
            vector <int> vec;
            for (int j = i ; j < nums.size() ; j++)
            {
                vec.push_back(nums[j]);
                if (vec.size() == 3)
                {
                    ans.push_back(vec);
                    break;
                }
            }
        }

        for (auto &vec : ans)
        {
            for (int i = 0 ; i < 3 ; i++)
            {
                for (int j = i + 1 ; j < 3 ; j++)
                {
                    if (abs(vec[i] - vec[j] ) > k ) return {};
                }
            }
        }
        return ans;
    }
};
