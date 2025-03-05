class Solution {
    vector <TreeNode*> solve(int start , int end)
    {
        if (start > end) 
        {
            return {nullptr};
        }
        if (start == end)
        {
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector <TreeNode*> ans;
        for (int i = start ; i <= end ; i++)
        {
            vector <TreeNode*> left_BST = solve(start , i-1);
            vector <TreeNode*> right_BST = solve(i+1 , end);
            for (auto l : left_BST)
            {
                for (auto r : right_BST)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
