class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char n = '$';
        string t = s;
        char m = t[0];
        for (int i = 0 ; i < s.length() ; i++)
        {
            if (s[i] == m) t[i] = '0';
            if(s[i] == '9') continue;
            if (n == '$' || s[i] == n)
            {
                n = s[i];
                s[i] = '9';
            }
        } 

        return stoi(s) - stoi(t);
    }
};
