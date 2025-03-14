class Solution {
    bool canEat(vector<int>& piles, int h , int n)
    {
        int ans = 0;
        for (int i = 0 ; i < piles.size() ; i++)
        {
            ans += ceil((double)piles[i]/n);
            if (ans > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin() , piles.end());
        int l = 1;
        int ans;
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (canEat(piles , h , mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
