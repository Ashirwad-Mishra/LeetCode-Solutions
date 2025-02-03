class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> stck;
        for (auto c : tokens)
        {
            if ((c == "+" || c == "-" || c == "*" || c == "/") && !(stck.empty()))
            {
                int t1 = stck.top();
                stck.pop();
                int t2 = stck.top();
                stck.pop();
                if (c == "+") stck.push(t2 + t1);
                else if (c == "-") stck.push(t2 - t1);
                else if (c == "*") stck.push(t2 * t1);
                else if (c == "/") stck.push(t2 / t1);
            }
            else stck.push(stoi(c));
        }
        return stck.top();
    }
};
