class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,counter=0;
        for(char ch : s) {
            if(ch=='(') {
                open++;
            } else {
                if(open==0) {
                    counter++;
                } else {
                    open--;
                }
            }
        }
        counter += open;
        return counter;
    }
};
