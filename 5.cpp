class Solution {
private:
    bool isP(string &s , int i , int j)
    {
        while (i<=j)
        {
            if (s[i] != s[j]) return false;
            i++;
            j --;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        int count = 0;
        for (int i = 0 ; i < s.length() ; i++)
        {
            string t = "";
            int c = 0;
            for (int j = i ; j < s.length() ; j++)
            {
                t += s[j];
                c++;
                if (isP(s,i,j) && c > count) 
                {
                    ans = t;
                    count = c;
                }
            }
        }
        return ans;
    }
};
