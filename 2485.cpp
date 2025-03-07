class Solution {
public:
    int pivotInteger(int n) 
    {
        int totalSum = n * (n + 1) / 2;
        int x = sqrt(totalSum);
        return (x * x == totalSum) ? x : -1;
    }
};
