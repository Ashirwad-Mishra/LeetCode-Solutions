class Solution {
private:
    void helper(string &s , int i , vector <string>&ans)
    {
        if (i == s.length())
        {
            ans.push_back(s);
            return;
        }
        if (isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            helper(s , i+ 1 , ans);

            s[i] = toupper(s[i]);
            helper(s , i+1 , ans);
        }
        else helper(s , i+1 , ans);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector < string > ans;
        helper(s , 0 , ans);
        return ans;
    }
};
