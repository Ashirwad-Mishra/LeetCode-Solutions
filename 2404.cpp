class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map <int , int> memo;
        for (auto i : nums) if (i % 2 == 0) memo[i]++;
        int ans = -1;
        int counter = 0;
        for (auto &p : memo) 
        {
            if (p.second > counter) 
            {
                ans = p.first;
                counter = p.second;
            }
        }
        return   ans;
    }
};
