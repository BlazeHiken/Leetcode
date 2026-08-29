class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums) {
            if(mp.count(num)==1) {
                return true;
            }
            mp[num]++;
        }
        return false;
    }
};