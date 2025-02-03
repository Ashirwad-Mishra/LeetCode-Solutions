class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string , vector <string>> memo;
        for (auto &s : strs)
        {
            string t = s;
            sort(t.begin() , t.end());
            memo[t].push_back(s);
        }
        vector <vector <string>> ans;
        for (auto &p : memo)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
