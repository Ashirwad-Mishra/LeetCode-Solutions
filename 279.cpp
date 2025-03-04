class Solution {
    int solve(int n , unordered_map <int , int> &memo)
    {
        if (n == 0) return 0;
        if (memo.find(n) != memo.end()) return memo[n];
        int ans = INT_MAX;
        for (int i = 1 ; i*i <= n ; i++)
        {
            ans = min(ans , 1 + solve(n - i*i , memo));
        }
        return memo[n] = ans;
    }
public:
    int numSquares(int n) {
        unordered_map <int , int> memo;
        return solve(n , memo);
    }
};

class Solution {
    int solve(int n , vector<int> &memo)
    {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];
        int ans = INT_MAX;
        for (int i = 1 ; i*i <= n ; i++)
        {
            ans = min(ans , 1 + solve(n - i*i , memo));
        }
        return memo[n] = ans;
    }
public:
    int numSquares(int n) {
        vector <int> memo(n + 1,-1);
        return solve(n , memo);
    }
};
