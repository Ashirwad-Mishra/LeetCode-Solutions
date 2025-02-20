class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> trusts(n + 1 , 0);
        vector <int> TBL(n + 1 , 0);
        for (auto v : trust)
        {
            int trusted = v[1];
            int trustedBy = v[0];
            trusts[trusted]++;
            TBL[trustedBy]++;
        }
        for (int i = 1 ; i <= n ; i++)
        {
            if (trusts[i] == n - 1 && TBL[i] == 0) return i;
        }
        return -1;
    }
};
