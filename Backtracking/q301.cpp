class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ansclean;
        unordered_set<string> ans;
        int open = 0;
        string current = "";
        int bestsize = 0;

        vector<int> closeLeft(s.size()+1,0);

        for(int i=s.size()-1; i >= 0;i--) {
            closeLeft[i] = closeLeft[i+1] + (s[i]==')');
        }

        backtrack(0,current,open,s,closeLeft,ans,bestsize);
        for(string valid : ans) {
            ansclean.push_back(valid);
        }
        return ansclean;
    }

    void backtrack(int index, string current, int &open, const string &s, vector<int> &closeLeft, unordered_set<string> &ans, int &bestsize) {
        if(open > closeLeft[index])
        return;

        if(current.size() + (s.size() - index) < bestsize)
            return;

        if(index==s.size()) {
            if(open==0) {
                if(current.size()>bestsize) {
                    ans.clear();
                    ans.insert(current);
                    bestsize = current.size();
                } else if(current.size()==bestsize) {
                    ans.insert(current);
                }
            }
            return;
        }
        char ch = s[index];
        if(ch!='(' && ch!=')') {
            current.push_back(ch);
        }
        if(ch=='(') {
            current.push_back('(');
            open++;
            backtrack(index+1,current, open, s, closeLeft, ans, bestsize);
            current.pop_back();
            open--;
        }
        backtrack(index+1,current, open, s, closeLeft, ans, bestsize);
        if(ch==')') {
            if(open>0) {
                current.push_back(')');
                open--;
                backtrack(index+1,current, open, s, closeLeft, ans, bestsize);
                current.pop_back();
                open++;
            } else if(open==0) {
                return;
            }
        }
    }
};