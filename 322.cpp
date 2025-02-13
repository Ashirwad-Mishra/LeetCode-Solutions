class Solution {
public:
    int helper(vector<int>& coins, int amount, map<int, int>& memo) 
    {
        if (amount < 0) return -1; // No solution
        if (amount == 0) return 0; // Base case
        if (memo.find(amount) != memo.end()) return memo[amount]; // Use memoization
        
        int minCoins = INT_MAX;
        for (int coin : coins) 
        {
            int res = helper(coins, amount - coin, memo);
            if (res >= 0 && res < minCoins) 
            {
                minCoins = 1 + res;
            }
        }
        
        // Store the result in memo
        memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount < 1) return 0;
        map<int, int> memo;
        return helper(coins, amount, memo);
    }
};
