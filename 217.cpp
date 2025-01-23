class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> memo;
        for (int i = 0 ; i <nums.size() ; i++)
        {
            memo[nums[i]]++;
        }
        for (auto &pair : memo)
        {
            if (pair.second > 1) return true; 
        }
        return false;
    }
};
