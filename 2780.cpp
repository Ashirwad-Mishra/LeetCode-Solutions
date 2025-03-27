class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int , int> m;
        for (auto &i : nums) m[i]++;
        int dominant = INT_MIN;
        int DF = 0;
        for (auto &p : m)
        {
            if (p.second > nums.size()/2) 
            {
                dominant = p.first;
                DF = p.second;
                break;
            }
        }       
        int count_l = 0;
        int count_r = DF;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] == dominant)
            {
                count_l++;
                count_r--;
            }
            if (count_l > (i + 1)/2  && count_r > (nums.size() - 1 - i)/2) return i;
        }
        return -1;
    }
};
