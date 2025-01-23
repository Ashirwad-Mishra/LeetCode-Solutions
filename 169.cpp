class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> memo;
        for (int i : nums) memo[i]++;
        pair <int , int> ans = make_pair(0,0) ;
        for (auto &p : memo)
        {
            if (ans.second < p.second) ans = p;
        }
        return ans.first;
    }
};
