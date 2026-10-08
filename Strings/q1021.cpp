class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";
        for(char ch : s) {
            if(ch=='(') {
                if(open!=0) {
                    ans.push_back(ch);
                }
                open++;
            } else {
                if(open!=1) {
                   ans.push_back(ch);
                }
                open--;
            }
        }
        return ans;
    }
};