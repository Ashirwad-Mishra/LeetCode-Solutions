class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int steps = 0;
        int n = operations.size();
        for (int i = min(n - 1 , 47) ; i >= 0; i--) 
        {
            long long half = 1LL << i;
            if (k > half) 
            {
                steps += operations[i];
                k -= half;
            }
        } 
        return 'a' + (steps % 26);
    }
};
