class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> prefix(n + 1, 0);  // Use long long to handle large inputs

        for (int i = 1; i <= n; i++) 
        {
            prefix[i] = prefix[i - 1] + differences[i - 1];
        }

        long long minPrefix = *min_element(prefix.begin(), prefix.end());
        long long maxPrefix = *max_element(prefix.begin(), prefix.end());

        long long rangeMin = lower - minPrefix;
        long long rangeMax = upper - maxPrefix;

        return rangeMax >= rangeMin ? (rangeMax - rangeMin + 1) : 0;
    }
};
