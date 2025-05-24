// in CPP
class Solution {
private: 
    int help(vector<int>& nums , int i , vector <int> &memo)
    {
        if (i >= nums.size() ) return 0;
        if (memo[i] != -1) return memo[i];
        return memo[i] =  max(help(nums , i + 1  , memo) , nums[i] + help(nums , i + 2 , memo));
    }
public:
    int rob(vector<int>& nums) {
        vector <int> memo (nums.size() , -1);
        return help(nums ,0 , memo);
    }
};


// In Java
class Solution {
    private int help(int []nums , int []memo , int idx)
    {
        if (idx >= nums.length) return 0;
        if (memo[idx] != -1) return memo[idx];

        int a = nums[idx] + help(nums , memo , idx + 2);
        int b = help(nums , memo , idx + 1);
        return memo[idx] = Math.max(a,b);
    }
    public int rob(int[] nums) {
        int[] memo = new int[nums.length + 1];
        Arrays.fill(memo , -1);
        return help(nums , memo , 0); 
    }
}
