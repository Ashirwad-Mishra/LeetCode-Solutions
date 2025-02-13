class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap;
        int ans = 0;
        for (auto i : nums)
        {
            minHeap.push(i);
        }
        while (minHeap.top() < k)
        {
            long long int x = minHeap.top();
            minHeap.pop();
            long long int y = minHeap.top();
            minHeap.pop();
            long long int temp = min(x, y) * 2 + max(x, y);
            minHeap.push(temp);
            ans++;
        }
        return ans;
    }
};
