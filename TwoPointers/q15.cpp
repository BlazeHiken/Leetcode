class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int left,right,n,sum;
        n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++) {
            if(i!=0 && nums[i-1]==nums[i]) continue;
            left=i+1;
            right=n-1;
            while(left<right) {
                sum=nums[left]+nums[right];
                if(sum==-nums[i]) {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) {
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]) {
                        right--;
                    }
                } else if(sum>-nums[i]) {
                    right--;
                } else if(sum<-nums[i]) {
                    left++;
                }
            }
        }
        return ans;
    }
};