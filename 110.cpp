class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(height(root -> left) - height(root -> right)) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
private:
    int height(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int l = height(root -> left);
        int r = height(root -> right);
        return max(l , r) + 1;
    }
};
