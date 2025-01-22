class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector <int> ans;
        map <int , int> memo;
        for (int i : arr1)
        {
            memo[i]++;
        }
        for (int i : arr2)
        {
            int &n = memo[i];
            while (n--)
            {
                ans.push_back(i);
            }
            memo.erase(i);
        }
        for (auto &p : memo)
        {
            int &n = p.second;
            while(n--)
            {
                ans.push_back(p.first);
            }
            memo.erase(p.first);
        }
        return ans;
    }
};
