class Solution {
    vector<vector<int>>mergeIntervals(vector<vector<int>>axis)
    {
        if (axis.empty()) return {};
        vector <vector<int>>ans;
        sort(axis.begin() , axis.end());
        int start = axis[0][0];
        int end = axis[0][1];
        for (int i = 1 ; i < axis.size() ; i++)
        {
            if (axis[i][0] < end)
            {
                end = max(end , axis[i][1]);
            }
            else
            {
                ans.push_back({start , end});
                start = axis[i][0];
                end = axis[i][1];
            }
        }
        return ans;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector <vector <int>> x;
        vector <vector<int>>y;
        for (auto &v : rectangles)
        {
            int xi = v[0];
            int yi = v[1];
            int xl = v[2];
            int yl = v[3];
            x.push_back({xi,xl});
            y.push_back({yi , yl});
        }
        x = mergeIntervals(x);
        y = mergeIntervals(y);
        return (y.size()>=2 || x.size() >= 2) ;
    }
};
