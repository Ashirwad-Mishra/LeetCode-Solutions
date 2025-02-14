class Solution {
private:
    int solve(string &word1 , string &word2 , int i , int j , int n , int m , map <pair<int , int> , int> &memo)
    {
        if (i == n) return m - j;
        if (j == m) return n - i;
        if (memo.find(make_pair(i , j)) != memo.end()) return memo[make_pair(i , j)];
        if (word1[i] == word2[j]) 
        {
            memo[make_pair(i , j)] = solve(word1 , word2 , i+ 1 , j + 1 , n ,m , memo) ;
            return memo[make_pair(i , j)];
        }
        else
        {
            int insertC = 1 + solve(word1 , word2 , i , j + 1 , n ,m , memo);
            int delC = 1 + solve(word1 , word2 , i+ 1 , j  , n ,m , memo);
            int replaceC = 1 + solve(word1 , word2 , i+ 1 , j + 1 , n ,m , memo);
            memo[make_pair(i , j)] = min({insertC , delC , replaceC}) ;
            return memo[make_pair(i , j)];
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        map <std :: pair<int , int> , int> memo;
        return solve(word1 , word2 , 0 , 0 , n , m ,memo);
    }
};
