class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        int i = 0;
        int j = 0;
        while (i < m)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n-1])
            {
                auto it = find(matrix[i].begin() , matrix[i].end(), target);
                return it != matrix[i].end();
            }
            else if (target > matrix[i][n-1]) i++;
            else break;
        }
        return false;
    }
};
