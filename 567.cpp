class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (m < n) return false;
        int le = 0;
        map <char , int> memo1;
        for (auto c : s1)
        {
            memo1[c]++;
        }
        map <char , int> memo2;
        for (int i = 0 ; i < m ; i++)
        {
            memo2[s2[i]]++;
            
            while (i - le + 1 > n)
            {
                memo2[s2[le]]--;
                if (memo2[s2[le]] == 0) memo2.erase(s2[le]);
                le++;
            }
            if (memo1 == memo2) return true;
        }
        return false;
    }
};
