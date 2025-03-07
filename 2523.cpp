// Brute force with sieve of erathosthnes
class Solution {
    bool isPrime(int n) 
    {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) 
        {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector <int> v;
        for (int i = left ; i<= right ; i++)
        {
            if (isPrime(i)) v.push_back(i);
        }
        int ans = INT_MAX;
        int a = -1 , b = -1;
        for (int i = 1 ; i < v.size() ; i++)
        {
            if (v[i] - v[i-1] < ans)
            {
                ans = v[i] - v[i-1];
                a = v[i-1];
                b = v[i];
            }
        }
        return {a,b};
    }
};
