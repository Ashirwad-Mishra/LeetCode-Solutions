class Solution {
    TreeNode* ans;
    int depth(TreeNode* root)
    {
        if (!root) return -1;
        int DOL = depth(root -> left);
        int DOR = depth(root -> right);

        return max(DOL , DOR) + 1;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int DOL = depth(root -> left);
        int DOR = depth(root -> right);

        if (DOL > DOR) subtreeWithAllDeepest(root -> left);
        else if (DOR > DOL) subtreeWithAllDeepest(root -> right);
        else ans = root;

        return ans;
    }
};
