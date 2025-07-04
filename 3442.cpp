class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for (int f : freq) 
        {
            if (f == 0) continue;
            if (f % 2 != 0) maxOdd = max(maxOdd, f);
            else minEven = min(minEven, f);
        }

        if (maxOdd == INT_MIN || minEven == INT_MAX) return -1; 
        return maxOdd - minEven;
    }
};
