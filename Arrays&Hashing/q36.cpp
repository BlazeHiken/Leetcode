class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;
        for(int i=0; i<9; i++) {           //check rows
            for(int j=0; j<9; j++) {
                if(board[i][j]=='.') {
                    continue;
                }
                if(st.count(board[i][j])) {
                    return false;
                } else {
                    st.insert(board[i][j]);
                }
            }
            st.clear();
        }

        for(int i=0; i<9; i++) {            //check columns
            for(int j=0; j<9; j++) {
                if(board[j][i]=='.') {
                    continue;
                }
                if(st.count(board[j][i])) {
                    return false;
                } else {
                    st.insert(board[j][i]);
                }
            }
            st.clear();
        }

        for(int i=0; i<9; i+=3) {            //check boxes
            for(int j=0; j<9; j+=3) {
                for(int k=i; k<i+3; k++) {
                    for(int l=j; l<j+3; l++) {
                        if(board[k][l]=='.') {
                            continue;
                        }
                        if(st.count(board[k][l])) {
                            return false;
                        } else {
                            st.insert(board[k][l]);
                        }
                    }
                }
                st.clear(); 
            }
        }
        return true;
    }
};