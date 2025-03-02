class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map <int , int> m;
        for (auto v : nums1) m[v[0]] += v[1];
        for (auto v : nums2) m[v[0]] += v[1];
        vector<vector<int>> ans;
        for (auto p : m)
        {
            vector <int> v;
            v.push_back(p.first);
            v.push_back(p.second);
            ans.push_back(v);
        }
        return ans;
    }
};
