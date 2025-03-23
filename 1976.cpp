class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        int MOD = 1e9 + 7;
        
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);
        for (auto &temp : roads) 
        {
            int u = temp[0], v = temp[1], w = temp[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Min-heap priority queue
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        vector<long long> minCost(n, LLONG_MAX); 
        vector<int> times(n, 0);

        pq.push({0, 0});
        minCost[0] = 0;
        times[0] = 1;

        while (!pq.empty()) 
        {
            long long cost = pq.top().first; 
            int dest = pq.top().second;
            pq.pop();

            for (auto &v : adj[dest]) 
            {
                int newNode = v.first;
                int wt = v.second;

                
                if (minCost[newNode] > cost + wt) 
                {
                    minCost[newNode] = cost + wt;
                    times[newNode] = times[dest]; 
                    
                    pq.push({minCost[newNode], newNode});
                } 
                else if (minCost[newNode] == cost + wt) 
                {
                    times[newNode] = (times[newNode] + times[dest]) % MOD;
                }
            }
        }
        
        return times[n - 1];
    }
};
