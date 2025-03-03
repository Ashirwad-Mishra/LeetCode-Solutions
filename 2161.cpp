class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> LTP;
        vector <int> MTP;
        vector<int> PC;
        for (auto i : nums) 
        {
            if (i < pivot) LTP.push_back(i);
            else if (i == pivot) PC.push_back(i);
            else MTP.push_back(i);
        }
        vector <int> ans(LTP.begin() , LTP.end());
        for (auto i : PC) ans.push_back(i);
        for (auto i : MTP) ans.push_back(i);
        return ans;
    }
};
