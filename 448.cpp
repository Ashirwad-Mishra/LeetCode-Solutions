class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size() ;
        vector <bool> t(n+1 , false);
        for (auto i : nums) t[i] = true;
        vector <int> ans;
        for (int i = 0 ; i <= n ; i++)
        {
            if (i && !t[i]) ans.push_back(i);
        }
        return ans;
    }
};
