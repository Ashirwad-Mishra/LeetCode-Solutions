class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector <int> ans (n , -1);
        for (int i = 0 ;  i < n ; i++)
        {
            auto it = find(nums2.begin() , nums2.end() , nums1[i]);
            for (auto j = it + 1 ; j < nums2.end(); j++ )
            {
                if (*j > nums1[i]  ) 
                {
                    ans[i] = *j ;
                    break;
                }
            }
        }
        return ans;
    }
};
