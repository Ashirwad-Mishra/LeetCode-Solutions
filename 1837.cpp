class Solution {
public:
    int sumBase(int n, int k) {
        vector <int> s;
        while (n > 0)
        {
            s.push_back( n % k) ;
            n /= k;
        }
        return accumulate(s.begin() , s.end() , 0);
    }
};
