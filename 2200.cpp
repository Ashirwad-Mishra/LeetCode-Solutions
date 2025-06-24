class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector <int> ans;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            for (int j = 0 ; j < nums.size() ; j++)
            {
                if (nums[j] == key && abs(i - j) <= k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector <int> vec;
        for (int i = 0 ; i < nums.size() ; i++) 
        {
            if (nums[i] == key) vec.push_back(i);
        }
        vector <int> ans;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            for (int j = 0 ; j < vec.size() ; j++)
            {
                if (abs(i - vec[j]) <= k) 
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) 
        {
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) 
            {
                if (nums[j] == key) 
                {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
