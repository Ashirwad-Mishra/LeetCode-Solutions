class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int le = 0;
        long long ans = 0;
        long long sum = 0;
        for (int i =  0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            while (sum * (i - le + 1) >= k)
            {
                sum -= nums[le];
                le++;
            }
            ans += i - le + 1;
        }
        return ans;
    }
};
