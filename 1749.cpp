class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, temp = 0, le = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            temp += nums[i];
            maxSum = max(maxSum, temp);
            if (temp < 0) 
            {
                temp = 0;
                le = i + 1;
            }
        }

        int minSum = INT_MAX, t = 0, l = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            t += nums[i];
            minSum = min(minSum, t);
            if (t > 0) 
            {
                t = 0;
                l = i + 1;
            }
        }
        return max(maxSum, abs(minSum));
    }
};

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;
        
        for (int num : nums) 
        {
            currMax = max(currMax + num, num); // Kadane's for max subarray sum
            currMin = min(currMin + num, num); // Kadane's for min subarray sum
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        
        return max(maxSum, abs(minSum));
    }
};
