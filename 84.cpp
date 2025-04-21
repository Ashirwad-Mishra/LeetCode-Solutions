class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevMin(n), nxtMin(n);
        stack<int> st;

        for (int i = 0; i < n; i++) 
        {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            prevMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) 
        {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nxtMin[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) 
        {
            int width = nxtMin[i] - prevMin[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};
