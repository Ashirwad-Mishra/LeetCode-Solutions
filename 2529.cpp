class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int p=0 , nn = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] > 0) p ++;
            else if (nums[i] < 0) nn++;
        }
        return max(p , nn);
    }
};
