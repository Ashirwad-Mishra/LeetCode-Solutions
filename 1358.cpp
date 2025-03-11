// using map
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int le = 0;
        unordered_map<char, int> m;
        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            m[s[i]]++;

            while (m.size() == 3) 
            { 
                ans += (n - i); 
                m[s[le]]--;
                if (m[s[le]] == 0) m.erase(s[le]);
                le++; 
            }
        }

        return ans;
    }
};


// without map
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int le = 0;
        int ans = 0;
        vector <int> m(3);
        for (int i = 0; i < n; i++) 
        {
            m[s[i] - 'a']++;

            while (m[0] && m[1] && m[2] ) 
            { 
                ans += (n - i); 
                m[s[le]- 'a']--;
                le++; 
            }
        }

        return ans;
    }
};
