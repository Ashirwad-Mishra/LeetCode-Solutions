class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for (int i = 1 ; i < 7 ; i++)
        {
            int temp = 0;
            int j;
            for (j = 0 ; j < tops.size() ; j++)
            {
                if ( i == tops[j]) continue;
                else if (i != bottoms[j])
                {
                    break;
                }
                else 
                {
                    swap(tops[j] , bottoms[j]);
                    if (i == tops[j]) temp++;
                    swap(tops[j] , bottoms[j]);
                }
            }
            ans = j == tops.size() ? min(temp , ans) : ans;
        }
        for (int i = 1 ; i < 7 ; i++)
        {
            int temp = 0;
            int j;
            for (j = 0 ; j < bottoms.size() ; j++)
            {
                if ( i == bottoms[j]) continue;
                else if (i != tops[j])
                {
                    break;
                }
                else 
                {
                    swap(tops[j] , bottoms[j]);
                    if (i == bottoms[j]) temp++;
                    swap(tops[j] , bottoms[j]);
                }
            }
            ans = j == tops.size() ? min(temp , ans) : ans;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
