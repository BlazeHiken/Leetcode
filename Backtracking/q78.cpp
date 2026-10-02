class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        int index = 0;
        backtrack(index, nums, ans, current);
        return ans;
    }

    void backtrack(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &current) {
        if(index==nums.size()) {
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        backtrack(index+1, nums, ans, current);
        current.pop_back();
        backtrack(index+1, nums, ans, current);
    }
};