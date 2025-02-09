class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector <int> iV;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            iV.push_back(i - nums[i]);
        }
        long long count = 0;
        map <int , int> memo;
        for (auto i = 0 ; i < iV.size() ; i++)
        {
            count += i - memo[iV[i]];
            memo[iV[i]]++;
        }
        return count;
    }
};
