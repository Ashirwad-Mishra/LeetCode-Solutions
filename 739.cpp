class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> h;
        vector <int> ans(temperatures.size() , 0);
        for (int i = 0 ; i < temperatures.size() ; i++)
        {
            while (!h.empty() && temperatures[i] > temperatures[h.top()])
            {
                int idx = h.top();
                h.pop();
                ans[idx] = i - idx;
            }
            h.push(i);
        }
        return ans;
    }
};
