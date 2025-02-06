class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return IsSame(root->left, root->right);
    }
    
    bool IsSame(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && IsSame(left->left, right->right) && IsSame(left->right, right->left);
    }
};
