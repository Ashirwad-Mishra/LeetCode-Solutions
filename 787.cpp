class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<pair<int, int>>> memo;
        for (int i = 0; i < flights.size(); i++) 
        {
            int source = flights[i][0];
            int target = flights[i][1];
            int price = flights[i][2];
            memo[source].push_back({target, price}); 
        }

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        dist[src] = {0, 0};
        minHeap.push({0, src, 0}); // {cost, node, stops}

        while (!minHeap.empty()) 
        {
            int dis = minHeap.top()[0];
            int node = minHeap.top()[1];
            int stops = minHeap.top()[2];
            minHeap.pop();

            if (node == dst) return dis; 
            if (stops > k) continue; 

            for (auto i : memo[node]) 
            {
                int edgeNode = i.first;
                int edgePrice = i.second;
                
                if (dis + edgePrice < dist[edgeNode][0] || stops + 1 < dist[edgeNode][1]) 
                {
                    dist[edgeNode][0] = dis + edgePrice;
                    dist[edgeNode][1] = stops + 1;
                    minHeap.push({dist[edgeNode][0], edgeNode, stops + 1});
                }
            }
        }

        return dist[dst][0] == INT_MAX ? -1 : dist[dst][0];
    }
};
