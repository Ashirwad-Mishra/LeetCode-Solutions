class Solution {
    int solve(vector <int>&memo)
    {
        int ways = 0;
        for (int i = 0 ; i < 26 ; i++)
        {
            if (memo[i] > 0)
            {
                memo[i]--;
                ways += 1 + solve(memo);
                memo[i]++;
            }
        }
        return ways;
    }
public:
    int numTilePossibilities(string tiles) {
        vector <int> memo(26,0);
        for (char c: tiles) memo[c - 'A']++;
        return solve(memo);
    }
};
// with map :-
class Solution {
    int solve(map <char , int>&memo)
    {
        int ways = 0;
        for (auto &p : memo)
        {
            if (p.second > 0)
            {
                p.second--;
                ways += 1 + solve(memo);
                p.second++;
            }
        }
        return ways;
    }
public:
    int numTilePossibilities(string tiles) {
        map <char , int> memo;
        for (char c: tiles) memo[c]++;
        return solve(memo);
    }
};
