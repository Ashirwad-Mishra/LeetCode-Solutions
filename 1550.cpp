class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        for (int i = 0 , j = 1 , k = 2 ; k < n ; i++ , j++ , k++)
        {
            if (arr[i] % 2 && arr[j] % 2 && arr[k] % 2) return true;
        } 
        return false;
    }
};
