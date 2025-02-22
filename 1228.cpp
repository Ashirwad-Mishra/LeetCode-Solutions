class Solution {
    void solve(vector<pair<int, int>>& tree, TreeNode*& ans) 
    {
        if (tree.empty()) return;
        
        stack<TreeNode*> st;
        ans = new TreeNode(tree[0].first); // Root node
        st.push(ans);

        for (int i = 1; i < tree.size(); i++) 
        {
            int val = tree[i].first, depth = tree[i].second;
            TreeNode* node = new TreeNode(val);

            while (st.size() > depth) 
            {
                st.pop(); // Move up to the correct parent depth
            }

            if (!st.top()->left)
                st.top()->left = node;
            else
                st.top()->right = node;

            st.push(node);
        }
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> tree;
        int count = 0, num = 0;
        bool readingNumber = false;

        for (char c : traversal)
        {
            if (c == '-')
            {
                if (readingNumber)
                {
                    tree.push_back({num, count});
                    count = 0;
                    num = 0;
                    readingNumber = false;
                }
                count++;
            }
            else
            {
                num = num * 10 + (c - '0');
                readingNumber = true;
            }
        }
        if (readingNumber) tree.push_back({num, count}); // Add last node

        TreeNode* ans = nullptr;
        solve(tree, ans);
        return ans;
    }
};
