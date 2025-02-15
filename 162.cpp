class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak = *max_element(nums.begin() , nums.end());
        auto it = find(nums.begin() , nums.end() , peak);
        return distance(nums.begin() , it) ;
    }
};
