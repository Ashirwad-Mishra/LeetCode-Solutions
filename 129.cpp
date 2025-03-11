class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector <int> v;
        stack <pair <TreeNode* , string>> st;
        if (root) st.push({root,""});
        while (!st.empty())
        {
            auto p = st.top();
            auto t = p.first;
            auto s = p.second;
            s += t -> val + '0';
            st.pop();

            if (!(t -> left || t -> right))
            {
                v.push_back(stoi(s));
            }
            if (t -> left) st.push({t -> left , s});
            if (t -> right) st.push({t -> right , s });
        }
        return accumulate(v.begin() , v.end() , 0);
    }
};
