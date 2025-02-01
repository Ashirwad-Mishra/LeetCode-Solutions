/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int start , int end , int &idx)
    {
        if (start > end ) return nullptr;
        int rootVal = preorder[idx];
        int i;
        idx++;
        for (i = start ; i <= end ; i++)
        {
            if (inorder[i] == rootVal) break;
        }
        TreeNode* ans = new TreeNode(rootVal);
        ans -> left = helper(preorder , inorder , start , i - 1 , idx);
        ans -> right = helper(preorder , inorder , i+1 , end , idx);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return helper(preorder , inorder , 0 , n - 1 , idx);
    }
};
