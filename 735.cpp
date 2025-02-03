class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> s;
        for (auto &c : asteroids)
        {
            while (!s.empty() && c < 0 && s.top() > 0)
            {
                int sum = s.top() + c;
                if (sum < 0)
                {
                    s.pop();
                }
                else if (sum == 0)
                {
                    s.pop();
                    c = 0;
                }
                else c = 0;
            }
            if (c != 0) s.push(c);
        }
        int n = s.size();
        vector <int> ans(n);
        int i = n - 1;
        while (!s.empty())
        {
            int t = s.top();
            ans[i] = t;
            i--;
            s.pop();
        }
        return ans;
    }
};
