class Solution {
public:
    int helper (int n , map<int,int>&memo)
    {
        if (n<=3) return n;
        if (memo.find(n)!=memo.end()) return memo[n];
        memo[n] = helper(n-2,memo) + helper(n-1,memo);
        return memo[n];
    }
    int climbStairs(int n) {
        map <int , int> memo;
        if (n<=3) return n;
        return helper(n,memo);
    }
};
