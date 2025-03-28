class Solution
{
    bool isValid(int &x, int &y, int &m, int &n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        set<int> querySet(queries.begin(), queries.end());
        unordered_map<int, int> hashMap;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int count = 0;

        for (int q : querySet)
        {
            while (!minHeap.empty())
            {
                pair<int, pair<int, int>> temp = minHeap.top();
                minHeap.pop();
                int val = temp.first;
                int x = temp.second.first;
                int y = temp.second.second;

                if (val >= q)
                {
                    minHeap.push(temp);
                    break;
                }

                count++;
                for (auto &v : dirs)
                {
                    int newX = x + v[0];
                    int newY = y + v[1];
                    if (isValid(newX, newY, m, n) && !visited[newX][newY])
                    {
                        minHeap.push({grid[newX][newY], {newX, newY}});
                        visited[newX][newY] = true;
                    }
                }
            }
            hashMap[q] = count;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            ans[i] = hashMap[queries[i]];
        }

        return ans;
    }
};
