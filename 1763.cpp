class Solution {
public:
    string longestNiceSubstring(string s) {
        unordered_set <char> uset;
        for (auto c : s)
        {
            uset.insert(c);
        }
        for (int i = 0 ; i < s.length() ; i++)
        {
            if (uset.count(tolower(s[i])) && uset.count(toupper(s[i])) ) continue;
            string p = longestNiceSubstring(s.substr(0 , i));
            string q = longestNiceSubstring(s.substr(i+1));
            return p.length() >= q.length() ? p : q;
        }
        return s;
    }
};
