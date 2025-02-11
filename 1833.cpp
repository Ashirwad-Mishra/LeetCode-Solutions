class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int temp = 0 , ans = 0;
        for (auto i : costs)
        {
            if (temp + i > coins) break;
            temp += i;
            ans ++;
        }
        return ans;
    }
};
