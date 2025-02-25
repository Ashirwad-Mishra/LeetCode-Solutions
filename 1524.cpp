// with prefixsum array
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        vector<long long int> prefixSum;
        prefixSum.push_back(arr[0]);
        for (auto c : arr)
        {
            prefixSum.push_back(c + prefixSum.back());
        }
        int ans = 0;
        int even = 0;
        int odd = 0;
        for (auto i : prefixSum)
        {
            if (i % 2 != 0)
            {
                ans = (ans + even) % mod;
                odd++;
            }
            else if (i % 2 == 0)
            {
                even += 1;
                ans = (odd + ans) % mod;
            }
        }
        return ans;
    }
};

// without prefix sum array
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       int sum = 0;
       int even = 1;
       int odd = 0;
       int ans = 0;
       int mod = 1e9 + 7;
       for (auto i : arr)
       {
            sum += i;
            if (sum % 2 == 0)
            {
                even ++;
                ans = (ans + odd) % mod;
            }
            else if (sum % 2 != 0)
            {
                odd++;
                ans = (ans + even) % mod;
            }
       } 
       return ans;
    }
};
