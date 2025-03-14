class Solution {
    bool CanDistribute (vector<int>& candies , long long k , int n)
    {
        long long int d = 0;
        for (int i = 0 ; i < candies.size() ; i++)
        {
            d += candies[i] / n;
            if (d >= k) return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxC = *max_element(candies.begin() , candies.end());
        int l = 1 ; 
        int r = maxC;
        int ans = 0;
        while ( l <= r)
        {
            int mid = l + (r-l)/2;
            if (CanDistribute(candies , k , mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
