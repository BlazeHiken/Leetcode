class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        vector<int> bitCount(32, 0);
        long long maxSum = 0;
        for(int num : nums) {
            for(int b=0; b<32; b++) {
                if((num & (1 << b)) > 0) {
                    bitCount[b] += 1;
                }
            }
        }
        while(k--) {
            int num=0;
            for(int b=0; b<32; b++) {
                if(bitCount[b]>0) {
                    num |= (1 << b);
                    bitCount[b]--;
                }
            }
            long long sq = 1LL*num*num;
            maxSum = (maxSum+sq)%MOD;
        }
        return maxSum;
    }
};