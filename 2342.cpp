class Solution {
private:
    int SOD(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int NeededSum(vector<int>& nums , vector <int> &indiceList)
    {
        int ans = INT_MIN;
        for (int i = 0 ; i < indiceList.size() ; i++)
        {
            for (int j = i + 1 ; j < indiceList.size() ; j++)
            {
                int temp = nums[indiceList[i]] + nums[indiceList[j]];
                if (temp > ans) ans = temp;
            }
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        map <int , vector <int>> memo;
        for (int i =  0 ; i < nums.size() ; i++)
        {
            memo[SOD(nums[i])].push_back(i);
        }
        int ans = INT_MIN;
        for (auto &p : memo)
        {
            vector <int> tV = p.second;
            if (tV.size() < 2) continue;
            int temp = NeededSum(nums , tV) ; 
            if ( temp > ans) ans = temp;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
