class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n, -1);  
        stack<int> help;
        for (int i = 2 * n - 1; i >= 0; i--) 
        {
            while (!help.empty() && help.top() <= nums[i % n]) help.pop();
            if (!help.empty()) NGE[i % n] = help.top();
            help.push(nums[i % n]);
        }
        return NGE;
    }
};
