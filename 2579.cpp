// With vector
class Solution {
public:
    long long coloredCells(int n) {
        vector <long long> v;
        v.push_back(1);
        for (int i = 1 ; i < n ; i++)
        {
            v.push_back(4*i + v.back());
        }
        return v.back();
    }
};
// Without vector
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 2LL*n*(n-1);
    }
};
