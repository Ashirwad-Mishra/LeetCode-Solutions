class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2 ; i <= n ; i++)
        {
            string ns = "";
            int count = 1;
            for (int j = 1 ; j < s.length() ; j++)
            {
                if (s[j] == s[j-1]) count++;
                else
                {
                    ns += to_string(count);
                    ns += s[j-1];
                    count = 1;
                }
            }
            ns += to_string(count) + s.back();
            s = ns;
        }
        return s;
    }
};
