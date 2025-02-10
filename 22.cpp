class Solution {
private:
    void helper(vector <string> &ans , int l , int r , string temp)
    {
        if (l == 0 && r == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (l > 0)
        {
            helper(ans , l - 1 , r , temp + "(");
        }
        if (r > l)
        {
            helper(ans , l , r - 1 , temp + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        helper(ans , n , n , "");
        return ans;
    }
};
