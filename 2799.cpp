class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set <int> s(nums.begin() , nums.end());
        int ans = 0;
        int no_of_uniqs = s.size();
        for (int i = 0 ; i < nums.size() ; i++)
        {
            unordered_set <int> temp;
            for (int j = i ; j < nums.size() ; j++)
            {
                temp.insert(nums[j]);
                if (temp.size() == no_of_uniqs) ans++;
            }
        }

        return ans;
    }
};
