class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = INT_MIN;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            for (int j = i + 1 ; j < nums.size() ; j++)
            {
                for (int k = j + 1 ; k < nums.size(); k++)
                {
                    ans = max(ans , static_cast<long long>(nums[i] - nums[j])*nums[k]);
                }
            }
        }
        return ans < 0 ? 0 : ans;
    }
};
