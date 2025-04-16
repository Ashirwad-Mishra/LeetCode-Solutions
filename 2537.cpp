class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map <int , int> count;
        long long ans = 0 ;
        long long pair = 0;
        int i = 0 ;
        int j  = 0 ;
        int n = nums.size();
        while (j < n)
        {
            pair += count[nums[j]];
            count[nums[j]]++;
            while (pair >= k)
            {
                ans += n - j;
                count[nums[i]]--;
                pair -= count[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};
