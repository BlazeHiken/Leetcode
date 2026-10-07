class Solution {
public:
    int scoreOfParentheses(string s) {
        return countPar(0,s).first;
    }

    pair<int,int> countPar(int i, string &s) {
        int counter = 0;
        while(i<s.size() && s[i]!=')') {
            if(s[i+1]==')') {
                counter++;
                i += 2;
            } else {
                pair<int,int> p = countPar(i+1,s);
                counter += 2*p.first;
                i = p.second;
            }
        }
        return {counter,i+1};
    }
};