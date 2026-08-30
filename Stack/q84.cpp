class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0, area;
        heights.push_back(0);
        int n = heights.size();
        stack<int> stk;
        stk.push(0);
        for(int i=1; i<n; i++) {
            while(!stk.empty() && heights[i]<heights[stk.top()]) {
                area = heights[stk.top()];
                stk.pop();
                if(stk.empty()) {
                    area *= i;
                } else {
                    area *= i-stk.top()-1;
                }
                maxarea = max(maxarea,area);
            }
            stk.push(i);
        }
        return maxarea;
    }
};