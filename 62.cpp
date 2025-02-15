class Solution {
    int solve(int m , int n , map <pair<int , int> , int> &memo)
    {
        if (m == 0 || n == 0) return 0;
        if (m == 1 && n == 1) return 1;
        pair <int , int> p = make_pair(m , n);
        if (memo.find(p) != memo.end()) return memo[p];
        return memo[p] = solve(m - 1 , n , memo) + solve(m ,n- 1 , memo);
    }
public:
    int uniquePaths(int m, int n) {
        map <pair<int , int> , int> memo;
        return solve( m , n , memo);
    }
};
