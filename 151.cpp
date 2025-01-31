class Solution {
public:
    string reverseWords(string s) {
        stack<string> help;
        string t = "";

        for (auto c : s)
        {
            if (c == ' ' && !t.empty()) 
            {
                help.push(t);
                t = "";
            }
            else if (c != ' ') 
            {
                t += c;
            }
        }
        if (!t.empty()) help.push(t);

        string ans = "";
        while (!help.empty())
        {
            ans += help.top();
            help.pop();
            if (!help.empty()) ans += " ";
        }

        return ans;
    }
};
