class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a,b;
        stack<int> stk;
        for(const string &ch : tokens) {
            if(!(ch == "+" || ch == "-" || ch == "*" || ch == "/")) {
                stk.push(stoi(ch));
            } else {
                b = stk.top();stk.pop();
                a = stk.top();stk.pop();
                if(ch == "+") {
                    stk.push(a+b);
                } else if(ch == "-") {
                    stk.push(a-b);
                } else if(ch == "*") {
                    stk.push(a*b);
                } else if(ch == "/") {
                    stk.push(a/b);
                }
            }
        }
        return stk.top();
    }
};