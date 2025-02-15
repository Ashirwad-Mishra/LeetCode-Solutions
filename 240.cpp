class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0 , j = n - 1;
        while (i < m)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n-1])
            {
                auto it = find(matrix[i].begin() , matrix[i].end(), target);
                if ( it != matrix[i].end()) return true;
                else i++;
            }
            else if (target > matrix[i][n-1]) i++;
            else i++;
        }
        return false;
    }
};
