class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector <int> ans;
        int le = 0;
        map <char , int> memo1;
        for (auto c : p)
        {
            memo1[c]++;
        }
        map <char , int> memo2;
        for (int i = 0 ; i < m ; i++)
        {
            memo2[s[i]]++;
            
            while (i - le + 1 > n)
            {
                memo2[s[le]]--;
                if (memo2[s[le]] == 0) memo2.erase(s[le]);
                le++;
            }
            if (memo1 == memo2) ans.push_back(le);
        }
        return ans;
    }
};
