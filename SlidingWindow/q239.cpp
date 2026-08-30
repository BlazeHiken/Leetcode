class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[i]>dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        int l=0;
        for(int i=k; i<nums.size(); i++) {
            while(!dq.empty() && nums[i]>dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if(nums[l]==dq.front()) {
                dq.pop_front();
            }
            l++;
            ans.push_back(dq.front());
        }
        return ans;
    }
};