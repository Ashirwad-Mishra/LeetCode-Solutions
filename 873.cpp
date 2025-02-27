class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> set(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int a = arr[i], b = arr[j];
                int length = 2;
                while (set.find(a + b) != set.end()) 
                {
                    int c = a + b;
                    a = b;
                    b = c;
                    length++;
                }
                ans = max(ans, length);
            }
        }
        
        return ans > 2 ? ans : 0; 
    }
};
