class Solution {
    bool canFinish(vector<int>& ranks, int cars , long long time)
    {
        long long finished = 0;
        for (int i = 0 ; i < ranks.size() ; i++)
        {
            finished += static_cast<long long>(sqrt(time / ranks[i]));
            if (finished >= cars) return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long r = static_cast<long long>(*min_element(ranks.begin(), ranks.end())) * cars * cars;
        long long l = 1;
        long long ans = 0;
        while (l <= r)
        {
            long long mid = l + (r-l)/2;
            if (canFinish(ranks , cars , mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
