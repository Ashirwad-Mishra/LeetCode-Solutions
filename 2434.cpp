class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minChar(n + 1);
        char curr = s.back();
        minChar[n] = 'z';
        for (int i = n - 1; i >= 0; --i) 
        {
            curr = min(curr, s[i]);
            minChar[i] = curr;
        }

        string t = "";
        string paper = "";

        for (int i = 0; i < n; ++i) 
        {
            t += s[i];
            while (!t.empty() && t.back() <= minChar[i + 1]) 
            {
                paper += t.back();
                t.pop_back();
            }
        }

        while (!t.empty()) 
        {
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};
