class Solution {
private:
    bool DFS(unordered_map<int , vector <int>>& memo , vector <bool>& visited , int u , int v)
    {
        visited[u] = true;
        if (u == v) return true;
        for ( auto &i : memo[u])
        {
            if (visited[i]) continue;
            if (DFS(memo , visited , i , v)) return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int , vector <int>> memo;
        for (int i = 0 ; i < n ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            vector <bool> visited(n , false);
            if (memo.find(u) != memo.end() && memo.find(v) != memo.end() && DFS(memo ,visited , u , v))
            {
                return edges[i];
            }
            memo[u].push_back(v);
            memo[v].push_back(u);
        }
        return {};
    }
};
