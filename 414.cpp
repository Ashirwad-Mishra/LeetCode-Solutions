class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i = 1 ; i < nums.size() ; )
        {
            if (nums[i] == nums[i-1]) 
            {
                nums.erase(nums.begin() + i );
            }
            else i++;
        }
        if (nums.size() < 3) return nums[nums.size()-1];
        return nums[nums.size()-3];
    }
};
