class Solution {
    vector <int> parent;
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression applied
        }
        return parent[x];
    }
    void Union(int x , int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x != parent_y)
        {
            parent[parent_x] = parent_y;
        }
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector <int> cost(n, -1);
        for (int i = 0 ; i < n ; i++)
        {
            parent[i] = i;
        }
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int parent_u = find(u);
            int parent_v = find(v);
            if (parent_v != parent_u) 
            {
                Union(parent_u , parent_v);
                cost[parent_v] &= cost[parent_u]; // Ensure cost updates correctly
            }
            cost[parent_v] &= w;
        }
        vector <int> ans;
        for (auto &q : query)
        {
            int s = q[0];
            int dest = q[1];
            int parent_s = find(s);
            int parent_dest = find(dest);
            if (parent_s != parent_dest)
            {
                ans.push_back(-1);
            }
            else ans.push_back(cost[parent_s]);
        }
        return ans;
    }
};
