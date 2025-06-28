class myData
{
    public:
        int id;
        int data;
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector <myData> vec;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            vec.push_back({i , nums[i]});
        }
        sort(vec.begin() , vec.end() , [](auto &a , auto &b){
            return a.data > b.data;
        });

        vector <myData> temp(vec.begin() , vec.begin() + k);

        sort(temp.begin() , temp.end() , [](auto &a , auto &b){
            return a.id < b.id;
        });

        vector <int> ans;
        for (auto &p : temp)
        ans.push_back(p.data);

        return ans;
    }
};
