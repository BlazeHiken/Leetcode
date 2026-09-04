class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; //map is prefixsum : minimum index
        int ans = 0;
        int sum = 0; //prefix sum
        mp[0] = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) { // turns array of [0,1] to [-1,1] so that prefixsum 0 means equal 0s and 1s
                sum -= 1;
            } else {
                sum += 1;
            }
            if(mp.count(sum)) { // checks if current prefixsum existed before because we do x-x = 0, 0 means equal
                ans = max(ans,(i-mp[sum])); // for max length 
            } else {
                mp[sum] = i; //new prefixsum found
            }
        }
        return ans;
    }
};