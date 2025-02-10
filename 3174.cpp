class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (auto c : s)
        {
            if (isdigit(c) && !ans.empty()) ans.pop_back(); 
            else ans.push_back(c);
        }
        return ans;
    }
};
