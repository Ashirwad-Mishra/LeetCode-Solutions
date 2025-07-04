class Solution {
public:
    char kthCharacter(int k) {
        int t = ceil(log2(k));
        int steps = 0;
        while(t--)
        {
            int half = pow(2 , t);
            if (k > half)
            {
                k = k - pow(2 , t);
                steps ++;
            }
        }

        return 'a' + steps;
    }
};
