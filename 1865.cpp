class FindSumPairs {
    vector <int> &nums1;
    vector <int> &nums2;
    unordered_map <int , int> fq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1) , nums2(nums2) {
        for (auto &i : nums2) fq[i]++;
    }
    
    void add(int index, int val) {
        fq[nums2[index]]--;
        this->nums2[index] += val;
        fq[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int i = 0 ; i < nums1.size() ; i++)
        {
            int tot_ = tot - nums1[i];
            if (fq[tot_]) ans += fq[tot_];
        }
        return ans;
    }
};
