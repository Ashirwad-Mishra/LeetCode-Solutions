class Solution {
public:
    string minWindow(string s, string t) {
        int required = t.length();
        int n = s.length();
        if (required > n) return "";

        vector<int> memo(128, 0);
        for (char c : t) memo[c]++;

        int start_i = 0, minLen = INT_MAX;
        int left = 0, right = 0;

        while (right < n)
        {
            if (memo[s[right]] > 0) required--;
            memo[s[right]]--;

            while (required == 0)
            {
                int currLen = right - left + 1;
                if (currLen < minLen) 
                {
                    minLen = currLen;
                    start_i = left;
                }

                memo[s[left]]++;
                if (memo[s[left]] > 0) required++;
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start_i, minLen);
    }
};
