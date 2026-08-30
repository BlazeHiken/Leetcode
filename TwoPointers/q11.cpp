class Solution {
public:
    int maxArea(vector<int>& height) {
        int left,right,water=INT_MIN,n;
        n=height.size();
        left=0;
        right=n-1;
        while(left<right) {
            water = max(water,(right-left)*min(height[left],height[right]));
            if(height[left]<=height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return water;
    }
};