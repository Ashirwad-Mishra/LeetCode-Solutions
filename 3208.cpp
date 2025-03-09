class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> doubled(colors.begin(), colors.end());
        doubled.insert(doubled.end(), colors.begin(), colors.end());
        
        int totalN = doubled.size();
        int le = 0, count = 0;

        for (int i = 1; i < totalN; ++i) 
        {
            if (doubled[i] == doubled[i - 1]) 
            {
                le = i;
            }
            while (i - le + 1 >= k) 
            {
                if (le < n) 
                {
                    count++;
                }
                le++;
                if (le >= n) return count;
            }
        }
        return count;
    }
};
