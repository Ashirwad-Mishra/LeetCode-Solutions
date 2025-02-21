// with maps:-
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map <int , vector<pair<int , int>>>adj;
        for (auto v : edges)
        {
            int from = v[0];
            int to = v[1];
            int waight = v[2];
            adj[from].push_back({to , waight});
            adj[to].push_back({from , waight});
        }
        vector <vector <int>> record(n , vector <int>(n , INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0 ; i < n ; i++)
        {
            record[i][i] = 0;
            minHeap.push({0 , i});
            while (!minHeap.empty())
            {
                int node = minHeap.top().second;
                int dist = minHeap.top().first;
                minHeap.pop();
                for (auto &p : adj[node])
                {
                    int edge = p.first;
                    int waight = p.second;
                    if (record[i][edge] > dist + waight)
                    {
                        record[i][edge] = dist + waight;
                        minHeap.push({record[i][edge] , edge});
                    }
                }
            }
        }
        int ans = INT_MIN;
        int fq = -1;
        for (int i = 0 ; i < n ; i++)
        {
            int count = 0;
            for (int j = 0 ; j < n ; j++)
            {
                if (record[i][j] <= distanceThreshold && record[i][j] != 0)
                {
                    count++;
                }
            }
            if (fq == -1 || fq >= count )
            {
                ans = i;
                fq = count;
            }
        }
        return ans;
    }
};
// without using maps:-
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &v : edges)
        {
            int from = v[0];
            int to = v[1];
            int weight = v[2];
            adj[from].push_back({to, weight});
            adj[to].push_back({from, weight});
        }

        vector<vector<int>> record(n, vector<int>(n, INT_MAX));

        for (int src = 0; src < n; src++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            record[src][src] = 0;
            minHeap.push({0, src});

            while (!minHeap.empty())
            {
                int dist = minHeap.top().first;
                int node = minHeap.top().second;
                minHeap.pop();

                if (dist > record[src][node]) 
                    continue;

                for (auto &p : adj[node])
                {
                    int edge = p.first;
                    int weight = p.second;

                    if (record[src][edge] > dist + weight)
                    {
                        record[src][edge] = dist + weight;
                        minHeap.push({record[src][edge], edge});
                    }
                }
            }
        }

        int ans = -1, minCount = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (record[i][j] <= distanceThreshold && i != j)
                    count++;
            }

            if (count <= minCount)
            {
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }
};
