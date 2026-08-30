class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> ans(temperatures.size());
        stk.push(0);
        for(int i=1; i<temperatures.size(); i++) {
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()]) {
                ans[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};