class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp; // (remainder of sum/k) : freq
        int ans = 0;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int rem = ((sum % k) + k) % k; //most imp, converts -ve remainder to positive equivalent
            // if k=5, -1 becomes 4 which is helpful because 4 - (-1) = 5 which is divisible by 5
            if(mp.count(rem)) {
                ans += mp[rem]; 
            }
            mp[rem]++;
        }
        return ans;
    }
};