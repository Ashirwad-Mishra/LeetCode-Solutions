class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char currChar = word[0];
        for (int i = 1 ; i < word.size() ; i++)
        {
            if (word[i] == currChar) ans++;
            else currChar = word[i];
        }
        return ans;
    }
};
