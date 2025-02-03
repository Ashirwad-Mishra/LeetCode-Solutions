class Solution {
private: 
    void help(vector<int>& height, vector<int>& LMR, vector<int>& RMR)
    {
        int n = height.size();
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t = max(t, height[i]);
            LMR[i] = t;
        }
        t = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            t = max(t, height[i]);
            RMR[i] = t;  
        }
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; 
        
        vector<int> LMR(n);
        vector<int> RMR(n);
        help(height, LMR, RMR);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = min(LMR[i], RMR[i]) - height[i];
            if (temp > 0) ans += temp;
        }
        return ans;
    }
};
