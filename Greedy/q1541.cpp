class Solution {
public:
    int minInsertions(string s) {
        int open=0, counter=0,i=0;
        while(i!=s.size()) {
            char ch = s[i];
            if(ch=='(') {
                open++;
            } else {
                if(open==0) {
                    if(i+1!=s.size() && s[i+1]==')') { // )) found, make it ()) and clear
                        counter += 1;
                        i++;
                    } else {
                        counter += 2; // )( found, make it ())( and clear ())
                    }
                } else {
                    if(i+1!=s.size() && s[i+1]==')') { // ()) found, clear
                        open--;
                        i++;
                    } else { // ()( found, make it ())( and clear ())
                        counter += 1;
                        open--;
                    }
                }
            }
            if(i==s.size()) break;
            i++;
        }
        counter += 2*open;
        return counter;
    }

};