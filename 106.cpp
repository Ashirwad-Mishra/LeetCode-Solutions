class Solution {
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx) 
    {
        if (start > end) return nullptr;

        int rVal = postorder[idx]; 
        idx--; 

        int i;
        for (i = start; i <= end; i++) 
        {
            if (inorder[i] == rVal) break;
        }

        TreeNode* ans = new TreeNode(rVal);

        ans->right = helper(inorder, postorder, i + 1, end, idx);
        ans->left = helper(inorder, postorder, start, i - 1, idx);

        return ans;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;  
        return helper(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};
