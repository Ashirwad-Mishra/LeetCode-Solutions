class Solution {
public:
    string frequencySort(string s) {
        map<char, int> memo;
        for (char c : s) 
        {
            memo[c]++;
        }
        vector <pair<char , int>> V(memo.begin() , memo.end());
        sort (V.begin() , V.end() , [](const pair<char , int> &a , const pair<char , int> &b)
        {
            return a.second > b.second;
        }
        );
        string ans = "";
        for (auto &p : V)
        {
            int t = p.second;
            while (t--) ans += p.first;
        }
        return ans;
    }
};
