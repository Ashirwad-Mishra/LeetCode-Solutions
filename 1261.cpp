class FindElements {
    void helper(TreeNode* root , int x)
    {
        if (root == nullptr) return;
        root -> val = x;
        elementSet.insert(x);
        helper(root -> left , 2*x + 1);
        helper(root -> right , 2*x + 2);
    }
public:
    FindElements(TreeNode* root) {
        if (root == nullptr) return;
        helper(root , 0);
    }
    unordered_set <int> elementSet;
    bool find(int target) {
        return elementSet.find(target) != elementSet.end();
    }
};
