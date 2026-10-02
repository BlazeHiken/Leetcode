class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current = "";
        int open = 0;
        int close = 0;
        backtrack(0, n, open, close, current, ans);
        return ans;
    }

    void backtrack(int index, int n, int open, int close, string current, vector<string> &ans) {
        if(index==n*2) {
            ans.push_back(current);
            return;
        }
        if(open<n) {
            current.push_back('(');
            open++;
            backtrack(index+1, n, open, close, current, ans);
            current.pop_back();
            open--;
        } 
        if(close<open) {
            current.push_back(')');
            close++;
            backtrack(index+1, n, open, close, current, ans);
            current.pop_back();
            close--;
        }
    }
};