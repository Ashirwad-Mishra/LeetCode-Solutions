class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1 ; i <= n ; i++ )
        {
            for (int j = 1 ; j <= n ; j++)
            {
                int t = i*i + j*j;
                int h = sqrt(t);
                if ( h*h == t && h <= n) ans++;
            }
        }
        return ans;
    }
};
