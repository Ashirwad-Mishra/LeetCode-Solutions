class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector <int>temp (3,0);
        for (int i : nums)
        {
            temp[i]++;
        }
        vector <int> ans;
        for (int i = 0 ; i < 3 ; i++)
        {
            int k = temp[i];
            while (k--) ans.push_back(i);
        }
        nums = ans;
    }
};
