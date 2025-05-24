class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> vec;
        int le = 0;
        map <int , int> mp;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;
            while (i - le + 1 > k)
            {
                mp[nums[le]]--;
                if (mp[nums[le]] == 0) mp.erase(nums[le]);
                le++;
            }
            if (i - le + 1 == k)
            {
                vec.push_back(mp.rbegin()->first);
            }
        }
        return vec;
    }
};
