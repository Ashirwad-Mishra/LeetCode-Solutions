class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c = 0;
        map <char,int> memo;
        int le = 0;
        int ans = INT_MIN;
        for (int i = 0 ; i < s.length() ; i++)
        {
            memo[s[i]]++;
            while(memo[s[i]] > 1)
            {
                memo[s[le]]--;
                if (memo[s[i]] == 0 ) memo.erase(s[le]);
                le++;
            }
            ans = max(ans , i - le + 1);
        }
        return (ans == INT_MIN) ? 0 : ans ;
    }
};
