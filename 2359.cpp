// Dijkastra's algo

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector <int> vec1(edges.size() , INT_MAX);
        unordered_map <int , vector<int>> mp;
        for (int i = 0 ; i < edges.size() ; i++)
        {
            if (edges[i] == -1) continue;
            mp[i].push_back(edges[i]);
        }

        priority_queue <pair <int , int> , vector <pair<int , int>> , greater <pair <int , int>>> minHeap;

        minHeap.push({0 , node1});
        vec1[node1] = 0;
        while(!minHeap.empty())
        {
            int root = minHeap.top().second;
            int wt = minHeap.top().first;
            minHeap.pop();
            for (auto &i : mp[root])
            {
                if (vec1[i] > wt + 1)
                {
                    minHeap.push({wt + 1 , i});
                    vec1[i] = min(wt + 1 , vec1[i]);
                }
            }
        }
        vector <int> vec2(edges.size() , INT_MAX);
        priority_queue <pair <int , int> , vector <pair<int , int>> , greater <pair <int , int>>> Heap;
        Heap.push({0 , node2});
        vec2[node2] = 0;
        while(!Heap.empty())
        {
            int root = Heap.top().second;
            int wt = Heap.top().first;
            Heap.pop();
            for (auto &i : mp[root])
            {
                if (vec2[i] > wt + 1)
                {
                    Heap.push({wt + 1 , i});
                    vec2[i] = min(wt + 1 , vec2[i]);
                }
            }
        }

        int ans = -1, minDist = INT_MAX;
        for (int i = 0; i < edges.size(); i++) 
        {
            if (vec1[i] != INT_MAX && vec2[i] != INT_MAX) 
            {
                int maxDist = max(vec1[i], vec2[i]);
                if (maxDist < minDist ) 
                {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans; 
    }
};


// BFS

class Solution {
    void bfs(vector<int>& edges, int node , vector <int> &dist)
    {
        queue <int> q;
        vector <bool> visited(edges.size() , false);

        dist[node] = 0;
        q.push(node);
        visited[node] = true;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            int next = edges[curr];
            if (next != -1 && !visited[next])
            {
                q.push(next);
                visited[curr] = true;
                dist[next] = dist[curr] + 1;
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector <int> vec1(edges.size() , INT_MAX) , vec2(edges.size() , INT_MAX);
        
        bfs(edges , node1 , vec1);
        bfs(edges , node2 , vec2);

        int ans = -1, minDist = INT_MAX;
        for (int i = 0; i < edges.size(); i++) 
        {
            if (vec1[i] != INT_MAX && vec2[i] != INT_MAX) 
            {
                int maxDist = max(vec1[i], vec2[i]);
                if (maxDist < minDist ) 
                {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans; 
    }
};
