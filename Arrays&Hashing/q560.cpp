class Solution {
public:

    //this is a pretty confusing concept
    //we calc prefix sums every iter 
    // if current prefix sum is sum and we have to find all subarrays from 0 to i that have the sum=k
    // so we check for sum-k because if my sum is 5, k is 3, so sum-k=2 and sum 2 exists before
    // then 0 to i = 5, minus 0 to x = 2, gives x to i = 3 which is k
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0; //used for prefix sum
        unordered_map<int,int> mp; //prefixsum : count
        int ans = 0; //num of valid subarrays
        mp[0] = 1; //prefix sum before array starts, this is very imp for sum-k=0
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i]; //update prefix sum

            if(mp.count(sum-k)) { //check if sum-k exists before
                ans+=mp[sum-k]; // all its occurances are valid subarrays
            }
            mp[sum]++; //update the map to show current sum
        }
        return ans;
    }
};