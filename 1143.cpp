class Solution {
    int solve(vector<vector<int>> &memo , int i , int j , string& text1, string& text2)
    {
        if (memo[i][j] != -1) return memo[i][j];
        if (i == text1.length() || j == text2.length()) return 0;
        if (text1[i] == text2[j]) 
        {
            memo[i][j] = 1 + solve(memo , i + 1 , j + 1 , text1 , text2);
            return memo[i][j];
        }
        else
        {
            memo[i][j] = max(solve(memo , i + 1 , j  , text1 , text2) , solve(memo , i  , j + 1 , text1 , text2));
            return memo[i][j];
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length() + 1 , vector <int>(text2.length() + 1 , -1));
        return solve(memo , 0 , 0 , text1 , text2);
    }
};
