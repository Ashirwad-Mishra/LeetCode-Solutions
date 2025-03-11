class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        while (nums.size())
        {
            unordered_set<int> s;
            bool isWorking = true;
            for (int i : nums)
            {
                if (s.find(i) != s.end())
                {
                    if (nums.size() >= 3)nums.erase(nums.begin() , nums.begin() + 3);
                    else nums.clear();
                    ans++;
                    isWorking = false;
                    break;
                }
                else s.insert(i);
            }
            if (isWorking) return ans;
        }
        return ans;
    }
};
