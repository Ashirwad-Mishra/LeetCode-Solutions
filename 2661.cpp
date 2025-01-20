class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map <int , vector<int>> lookUpTable;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j ++)
            {
                vector <int> temp ;
                temp.push_back(i);
                temp.push_back(j);
                lookUpTable[mat[i][j]] = temp;
            }
        }
        vector <int> rC(n , 0);
        vector <int>cC(m,0);
        for (int i = 0 ; i < arr.size() ; i++)
        {
            vector <int> here = lookUpTable[arr[i]];
            int RTI = here[0];
            rC[RTI]++;
            if (rC[RTI] == m) return i;
            int CTI = here[1];
            cC[CTI]++;
            if (cC[CTI] == n) return i; 
        }
        return 0;
    }
};
