class Solution 
{
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) 
    {
        int maxNode = 0;
        for (auto& v : edges1) 
        {
            maxNode = max({maxNode, v[0], v[1]});
        }
        for (auto& v : edges2) 
        {
            maxNode = max({maxNode, v[0], v[1]});
        }
        int n = maxNode + 1;

        vector<vector<int>> vec2(n, vector<int>(n, INT_MAX));
        unordered_map<int, vector<int>> mp2;
        for (auto& v : edges2) 
        {
            mp2[v[0]].push_back(v[1]);
            mp2[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < n; i++) 
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            vec2[i][i] = 0;
            minHeap.push({0, i});
            while (!minHeap.empty()) 
            {
                int currNode = minHeap.top().second;
                int wt = minHeap.top().first;
                minHeap.pop();
                for (auto& r : mp2[currNode]) 
                {
                    if (vec2[i][r] > wt + 1) 
                    {
                        vec2[i][r] = wt + 1;
                        minHeap.push({wt + 1, r});
                    }
                }
            }
        }

        vector<int> v2(n, 0);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (vec2[i][j] < k) 
                {
                    v2[i]++;
                }
            }
        }

        int CN = *max_element(v2.begin(), v2.end());

        vector<vector<int>> vec1(n, vector<int>(n, INT_MAX));
        unordered_map<int, vector<int>> mp1;
        for (auto& v : edges1) 
        {
            mp1[v[0]].push_back(v[1]);
            mp1[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < n; i++) 
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            vec1[i][i] = 0;
            minHeap.push({0, i});
            while (!minHeap.empty()) 
            {
                int currNode = minHeap.top().second;
                int wt = minHeap.top().first;
                minHeap.pop();
                for (auto& r : mp1[currNode]) 
                {
                    if (vec1[i][r] > wt + 1) 
                    {
                        vec1[i][r] = wt + 1;
                        minHeap.push({wt + 1, r});
                    }
                }
            }
        }

        vector<int> v1(n, CN);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (vec1[i][j] <= k) 
                {
                    v1[i]++;
                }
            }
        }

        return vector <int>(v1.begin() , v1.begin()+edges1.size() + 1);
    }
};
