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

// Above method was absolutely right. But, still dont use this method as it uses map to store the cordinates of the numbers. Through, above written logic you will end up taking 600 ms.
// instead use a vector of a pair as given below , through below written logic it shall only take 4ms.
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector <pair <int , int>> LUT(m*n+1);
        for (int i = 0 ; i < m ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                int t = mat[i][j] ; 
                LUT[t] = make_pair(i,j);
            }
        }
        vector <int> rC(m , 0);
        vector <int> cC(n , 0);
        for (int i = 0 ; i < arr.size() ; i++)
        {
            int t = arr[i];
            int r = LUT[t].first;
            rC[r]++;
            if (rC[r] == n) return i;
            int c = LUT[t].second;
            cC[c]++;
            if (cC[c] == m) return i;
        }
        return 0;
    }
};
