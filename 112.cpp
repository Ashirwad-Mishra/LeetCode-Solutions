class Solution {
public:
    vector <long long int> v;
    void PathSum(TreeNode* root, int s = 0)
    {
        if (root == nullptr) return;

        s += root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            v.push_back(s);
        }

        PathSum(root->left, s);
        PathSum(root->right, s);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        PathSum (root , 0);
        for (auto i : v)
        {
            if (i == targetSum) return true;
        }
        return false;
    }
};
