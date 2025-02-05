class Solution {
private:
    int helper(int n , vector <int> &memo)
    {
        if (memo[n] != 0) return memo[n];
        if (n == 0 || n == 1) return 1;
        int total = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            int left = helper(i - 1 , memo);
            int right = helper(n-i , memo);
            total += left * right; 
        }
        memo[n] = total;
        return memo[n];
    }
public:
    int numTrees(int n) {
        vector <int> memo(n + 1 , 0);
        return helper(n , memo);
    }
};
