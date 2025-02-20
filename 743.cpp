class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map <int , vector <pair<int , int>>> adj;
        vector <int> dist(n + 1 , INT_MAX);
        for (int i = 0 ; i < times.size() ; i++)
        {
            int source = times[i][0];
            int target = times[i][1];
            int waight = times[i][2];
            adj[source].push_back({target , waight});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        dist[k] = 0;
        minHeap.push({0 , k});
        while (!minHeap.empty())
        {
            int dis = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            for (auto it : adj[node])
            {
                int edgeWt = it.second;
                int edgeNode = it.first;
                if (dist[edgeNode] > dis + edgeWt)
                {
                    dist[edgeNode] = dis + edgeWt;
                    minHeap.push({dist[edgeNode] , edgeNode});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans ;
    }
};
