way 1:- using maps
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char , int> rM;
        map <char , int> mM;
        for (auto c : ransomNote) rM[c]++;
        for (auto c : magazine) mM[c]++;
        for (auto &p : rM)
        {
            if (mM[p.first] < p.second) return false;
        }
        return true;
    }
};

way 2:- without using maps , better and more efficient way
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> rM(26,0);
        vector <int> mM(26,0);
        for (auto c : ransomNote) rM[c - 'a']++;
        for (auto c : magazine) mM[c - 'a']++;
        for (int i = 0 ; i < 26 ; i++)
        {
            if (rM[i] > mM[i]) return false;
        }
        return true;
    }
};
