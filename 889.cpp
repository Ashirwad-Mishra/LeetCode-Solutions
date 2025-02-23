class Solution {
    vector<int> getSubvector(const vector<int>& vec, int start, int end) 
    {
        return vector<int>(vec.begin() + start, vec.begin() + end + 1);
    }

    void helper(const std::vector<int>& preorder, const std::vector<int>& postorder, TreeNode*& ans) 
    {
        if (preorder.empty() || postorder.empty()) 
        {
            return;
        }
        ans = new TreeNode(preorder[0]); // Properly initializing the node

        if (preorder.size() == 1) 
        {
            return;
        }

        int LNV = preorder[1];
        auto LPoE = std::find(postorder.begin(), postorder.end(), LNV);
        std::vector<int> LPost = getSubvector(postorder, 0, LPoE - postorder.begin());
        
        auto LPrE = preorder.begin();
        for (auto i : LPost) 
        {
            auto t = std::find(preorder.begin(), preorder.end(), i);
            LPrE = std::max(LPrE, t);
        }
        std::vector<int> LPre = getSubvector(preorder, 1, LPrE - preorder.begin());
        
        helper(LPre, LPost, ans->left);
        
        std::vector<int> RPost = getSubvector(postorder, LPoE - postorder.begin() + 1, postorder.size() - 2);
        std::vector<int> RPre = getSubvector(preorder, LPrE - preorder.begin() + 1, preorder.size() - 1);
        
        helper(RPre, RPost, ans->right);
    }
    
public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) 
    {
        TreeNode* ans = nullptr;
        helper(preorder, postorder, ans);
        return ans;
    }
};
