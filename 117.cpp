class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root == nullptr) return nullptr;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node* prev = nullptr;
            while (n--)
            {
                auto it = q.front();
                q.pop();
                if (prev)prev -> next = it;
                prev = it;
                if (it -> left) q.push(it -> left);
                if (it -> right) q.push(it -> right);
            }
        }
        return root;
    }
};
