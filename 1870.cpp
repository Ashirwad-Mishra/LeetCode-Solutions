class Solution {
    bool canReach(vector<int>& dist, double hour , int s)
    {
        double hT = 0;
        int n = dist.size();
        for (int i = 0 ; i < n ; i++)
        {
            if (i == n - 1) hT += (double)dist[i] / s;
            else hT += ceil((double)dist[i]/s);
            if (hT > hour) return false;
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour < dist.size() - 1) return -1;
        int r = 1e7;
        int l = 1;
        int ans = -1;
        while ( l <= r )
        {
            int mid = l +  (r-l)/2;
            if (canReach(dist , hour , mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
