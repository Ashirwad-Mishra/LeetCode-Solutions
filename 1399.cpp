class Solution {
    long long sum_of_digits(int n)
    {
        long long ans = 0;

        while(n > 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int countLargestGroup(int n) {
        unordered_map <long long ,vector <int> >mp;

        for (int i = 1 ; i <= n ; i++)
        {
            mp[sum_of_digits(i)].push_back(i);
        }

        int max_size = INT_MIN;
        for (auto &p : mp) max_size = max(max_size , static_cast<int>(p.second.size()));

        int ans = 0;
        for (auto &p : mp) 
        {
            if (p.second.size() == max_size) ans++;
        }
        return ans;
    }
};
