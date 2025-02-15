class Solution {
private:
    bool help(int i , int sum , string s , int num)
    {
        if (i == s.length()) return num == sum;
        if (sum > num) return false;
        bool p = false;
        for (int j = i ; j < s.length() ; j ++)
        {
            string temp = s.substr(i , j - i + 1);
            int t = stoi(temp);
            p = p || help(j+1 , sum + t , s , num);
            if (p== true) return true;
        }
        return p;
    }
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            int temp = i*i;
            if (help(0 , 0 , to_string(temp) , i)) sum += i*i;
        }
        return sum;
    }
};
