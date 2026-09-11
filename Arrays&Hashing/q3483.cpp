class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        int cnt = 0;
        for(int &digit : digits) {
            freq[digit]++;
        }
        for(int i=100; i<999; i=i+2) {
            int x = i;
            int temp[10];
            for(int i=0; i<10; i++) {
                temp[i]=freq[i];
            }
            while(x!=0) {
                if(temp[x%10]==0) {
                    break;
                } else {
                    temp[x%10]--;
                    x/=10;
                }
            }
            if(x==0) cnt++;
        }
        return cnt;
    }
};

//mathematical approach
class Solution {
public:
    int totalNumbers(auto& digits) {
        int f[10] = {0};
        int res = 0;

        for (auto& d : digits)
            f[d]++;

        for (int i = 1; i < 10; i++) //hundreds digit
            for (int j = 0; j < 10; j++) //tens digit
                for (int k = 0; k < 9; k += 2) //ones digit
                    res += f[i] > 0 && //check if hundreds digit is available
                           f[j] > (i == j) && //if i==j it means freq[i] should atleast be 2, (i==j) true=1, false=0
                           f[k] > (i == k) + (j == k); //same like tens but now checks for both tens and hundreds
                    // true is treated as 1 and false is treated as 0 so res is updated directly

        return res;
    }
};