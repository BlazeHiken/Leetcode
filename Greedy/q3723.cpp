class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        ans.reserve(num);
        
        int quo = sum/9;
        int rem = sum%9;
        if(num<quo || (num==quo && rem!=0)) {
            return "";
        }

        for(int i=0; i<quo; i++) {
            ans.push_back('9');
        }
        num -= quo;
        if(rem!=0) {
            ans.push_back(rem+'0');
            num--;
        }

        while(num!=0) {
            ans.push_back('0');
            num--;
        }
        return ans;
    }
};

