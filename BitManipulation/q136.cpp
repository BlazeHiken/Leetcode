class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++) {
            ans ^= nums[i]; //XOR of same number makes it 0, so remaining is unique
        }
        return ans;
    }
};