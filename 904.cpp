class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int le = 0;
        int ans = 0;
        map <int , int> memo;
        for (int i = 0 ; i < fruits.size() ; i++)
        {
            memo[fruits[i]]++;
            if (memo.size() <= 2)
            {
                ans = max(ans, i - le + 1);
            } 
            while (memo.size()>2)
            {
                memo[fruits[le]] --;
                if (memo[fruits[le]] == 0) memo.erase(fruits[le]);
                le++; 
            }
        }
        return ans;
    }
};
