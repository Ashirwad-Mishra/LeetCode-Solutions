class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> h;
        for (auto c : nums)
        {
            h.push_back(to_string(c));
        }
        sort(h.begin() , h.end() , [](const string &a , const string &b){
            return a + b > b + a;
        });
        string ans = "";
        for (auto c : h) ans += c;
        if (ans[0] == '0') return "0";
        return ans;
    }
};
