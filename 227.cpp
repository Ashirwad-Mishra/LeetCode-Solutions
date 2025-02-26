class Solution {
    bool isInteger(const string& str) 
    {
        if (str.empty() || ((str[0] != '+' && str[0] != '-') && !isdigit(str[0]))) return false;
        char* endptr = nullptr;
        strtol(str.c_str(), &endptr, 10);
        return *endptr == '\0';
    }

    int precedence(char op) 
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    int calculate(string s) {
        vector<string> postFix;
        stack<char> st;
        int n = s.length();
        int currNo = 0;
        
        for (int i = 0; i < n; i++) 
        {
            if (isdigit(s[i])) 
            {
                currNo = s[i] - '0';
                while (i < n - 1 && isdigit(s[i + 1])) 
                {
                    currNo = currNo * 10 + (s[i + 1] - '0');
                    i++;
                }
                postFix.push_back(to_string(currNo));
                currNo = 0;
            } 
            else if (s[i] == '(') 
            {
                st.push(s[i]);
            } 
            else if (s[i] == ')') 
            {
                while (!st.empty() && st.top() != '(') 
                {
                    postFix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();  // Remove '('
            } 
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
            {
                while (!st.empty() && precedence(st.top()) >= precedence(s[i])) 
                {
                    postFix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while (!st.empty()) 
        {
            postFix.push_back(string(1, st.top()));
            st.pop();
        }
        
        stack<int> help;
        for (auto str : postFix) 
        {
            if (isInteger(str)) 
            {
                help.push(stoi(str));
            } 
            else 
            {
                int n1 = help.top();
                help.pop();
                int n2 = help.top();
                help.pop();
                if (str == "+") help.push(n2 + n1);
                else if (str == "-") help.push(n2 - n1);
                else if (str == "*") help.push(n2 * n1);
                else if (str == "/") help.push(n2 / n1);
            }
        }
        
        return help.top();
    }
};
