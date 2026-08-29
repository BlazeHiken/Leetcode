class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(const int &num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int,int>> freq;
        for(auto &it : mp) {
            freq.push({it.second,it.first});
        }
        for(int i=0; i<k; i++) {
            ans.push_back(freq.top().second);
            freq.pop();
        }
        return ans;
    }
};