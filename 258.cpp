// t.c = O(n)
class Solution {
public:
    int digits(int num)
    {
        vector <int> digs;
        while (num > 0)
        {
            digs.push_back(num % 10);
            num/=10;
        }
        return accumulate(digs.begin() , digs.end() , 0);
    }
    int addDigits(int num) {
        while (num > 9)
        {
            num = digits(num);
        }
        return num;
    }
};

// t.c: O(1)
class Solution {
public:
    int addDigits(int num) {
        return num % 9 ? num % 9 : num ? 9 : 0;
    }
};
