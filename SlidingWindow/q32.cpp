class Solution {
public:
    int longestValidParentheses(string s) {
        int maxsize = 0;
        int l=0,r;
        int open=0;
        int close=0;

        for(r=0; r<s.size(); r++) { //left to right
            if(s[r]=='(') {
                open++;
            } else {
                close++;
            }
            while(close>open) { //shrink window if more close than open
                if(s[l]=='(') {
                    open--;
                } else {
                    close--;
                }
                l++;
            }
            if(open==close) { //valid parentheses
                maxsize=max(maxsize,r-l+1);
            }
        }
        l=s.size()-1;
        open=0;
        close=0;

        for(r=s.size()-1; r>=0; r--) { //right to left
            if(s[r]=='(') {
                open++;
            } else {
                close++;
            }
            while(open>close) { //same logic but here we deal with excess opens, shouldn't end with open
                if(s[l]=='(') {
                    open--;
                } else {
                    close--;
                }
                l--;
            }
            if(open==close) { //valid
                maxsize=max(maxsize,l-r+1);
            }
        }
        
        return maxsize;
    }
};