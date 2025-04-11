class Solution {
    bool isSymmetric(int num)
    {
        string temp = to_string(num);
        vector <char> V(temp.begin() , temp.end());
        if (V.size() % 2 != 0) return false;

        return accumulate(V.begin() , V.begin() + V.size() / 2 , 0ll) == accumulate(V.begin() + V.size() / 2  , V.end() , 0ll);
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low ; i <= high ; i++)
        {
            if (isSymmetric(i)) ans++;
        }
        return ans;
    }
};
