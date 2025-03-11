class Solution {
    void help(vector <int> &v , TreeNode* root)
    {
        if (root == nullptr) return;
        help(v , root -> left);
        v.push_back(root -> val);
        help(v , root -> right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector <int> v;
        help(v,root);
        nth_element(v.begin() , v.begin() + k - 1 , v.end());
        return v[k-1];
    }
};
