class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector <int> prefix;
        for (int i = 0 ; pow(3,i) <= n ; i++)
        {
            prefix.push_back(pow(3,i));
        } 
        int t = prefix.size();
        for (int i = t - 1 ; i >= 0 ; i--) 
        {
            if (n >= prefix[i]) n -= prefix[i];
        }
        return n == 0;
    }
};
