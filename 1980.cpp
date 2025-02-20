class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector <long long> v;
        for (auto s : nums)
        {
            long long t = stoll(s , nullptr , 2);
            v.push_back(t);
        }
        sort(v.begin() , v.end());
        long long theNumber = -1;
        int l = nums[0].length();
        for (long long i = v[0] ; i <= v.back() ; i++)
        {
            if (find(v.begin() , v.end() , i) == v.end()) 
            {
                theNumber = i;
                break;
            }
        }
        if (theNumber == -1) theNumber = v.back() + 1;
        bitset <16> binary(theNumber);
        string ans = binary.to_string();
        return ans.substr(16-l);
    }
};
