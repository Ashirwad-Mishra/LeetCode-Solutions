class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector <int> v;
        for (auto &t : matrix) v.insert(v.end() , t.begin() , t.end());
        sort(v.begin() , v.end());
        return v[k-1];
    }
};
