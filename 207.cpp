class Solution {
    bool TSC(unordered_map <int , vector <int>>&adj , vector <int> &indeg , int n)
    {
        queue<int>Q;
        int c = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            if (indeg[i] == 0) 
            {
                c++;
                Q.push(i);
            }
        }
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (auto &i : adj[u])
            {
                indeg[i]--;
                if (indeg[i] == 0)
                {
                    c++;
                    Q.push(i);
                }
            }
        }
        return c == n;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int , vector <int>>adj;
        vector <int> indeg(numCourses , 0);
        for (auto &v : prerequisites)
        {
            int i = v[0];
            int j = v[1];
            adj[j].push_back(i);
            indeg[i]++;
        }
        return TSC(adj , indeg , numCourses);
    }
};
