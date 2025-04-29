class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map <int , long long> mp;
        long long theFreq = 0;
        int maxElement = *max_element(nums.begin() , nums.end());
        int le = 0;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;
            theFreq = nums[i] == maxElement ? mp[nums[i]] : theFreq;
            while (theFreq >= k)
            {
                ans += nums.size() - i;
                mp[nums[le]]--;
                if (mp[nums[le]] == 0) mp.erase(mp[nums[le]]);
                le++;
                theFreq = nums[i] == maxElement ? mp[nums[i]] : theFreq;
            }
        }
        return ans;
    }
};
