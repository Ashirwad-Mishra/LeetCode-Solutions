class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends <= 1) return word;
        int n = word.length();
        int len = n - numFriends + 1;
        string ans = "";
        
        for (int i = 0; i < n; i++) 
        {
            string temp = "";
            for (int j = i ; j < n && temp.length() < len ; j++)
            {
                temp += word[j];
            }
            ans = max(ans , temp);
        }

        return ans;
    }
};
