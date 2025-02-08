class Solution {
public:
    int memofib(int n , map <int , int> &memo)
    {
        if (memo.find(n) !=) return memo[n];
        if (n<=2) return 1;
        memo[n] = memofib(n-2,memo) + memofib(n-1 , memo);
        return memo[n];
    }
    int fib(int n) {
        if (n==0) return 0;
        map <int , int> memo;
        return memofib(n,memo);
    }
};
