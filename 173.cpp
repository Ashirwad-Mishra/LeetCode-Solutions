class BSTIterator {
    void help(TreeNode*root)
    {
        if (root == nullptr) return;
        help(root -> left);
        v.push_back(root -> val);
        help(root -> right);
    }
public:
    vector <int> v;
    int ptr = 0;
    BSTIterator(TreeNode* root) {
        help(root);
    }
    
    int next() {
        int temp = v[ptr];
        ptr++;
        return temp;
    }
    
    bool hasNext() {
        return ptr != v.size();
    }
};
