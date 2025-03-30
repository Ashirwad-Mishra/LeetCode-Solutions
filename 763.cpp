class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> myMap;

        for (int i = 0; i < s.length(); i++) 
        {
            char c = s[i];
            if (myMap.find(c) == myMap.end()) 
            {
                myMap[c] = {i, i};
            } 
            else 
            {
                myMap[c].second = max(i, myMap[c].second);
            }
        }

        vector<vector<int>> pairs;
        for (auto &p : myMap) 
        {
            pairs.push_back({p.second.first, p.second.second});
        }
        sort(pairs.begin(), pairs.end());

        vector<vector<int>> UOV;
        int start = pairs[0][0], end = pairs[0][1];

        for (auto &v : pairs) 
        {
            if (v[0] <= end) 
            {  
                end = max(end, v[1]);
            } 
            else 
            { 
                UOV.push_back({start, end});
                start = v[0];
                end = v[1];
            }
        }
        UOV.push_back({start, end});  

        vector<int> ans;
        for (auto &v : UOV) 
        {
            ans.push_back(v[1] - v[0] + 1);
        }
        return ans;
    }
};
