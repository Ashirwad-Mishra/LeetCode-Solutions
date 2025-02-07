class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map <int , int> cM;
        map <int , int> bM;
        vector <int> ans;
        for (auto v : queries)
        {
            int ball = v[0];
            int color = v[1];
            if (bM.count(ball))
            {
                int temp = bM[ball];
                cM[temp] --;
                if (cM[temp] == 0) cM.erase(temp);
            }
            bM[ball] = color;
            cM[color]++;
            ans.push_back(cM.size());
        }
        return ans;
    }
};
