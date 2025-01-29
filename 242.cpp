class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <char> t1;
        vector <char> t2;
        for (auto c : s)
        {
            t1.push_back(c);
        }
        for (auto d : t)
        {
            t2.push_back(d);
        }
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        return t1 == t2;
    }
};
