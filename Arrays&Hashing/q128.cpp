class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxim = 0;
        unordered_set<int> st;
        for(const int &num : nums) {
            st.insert(num);
        }
        for(const int &num : st) {
            if(!st.count(num-1)) {
                int cnt = 1;
                while(st.count(num+cnt)) {
                    cnt++;
                }
                maxim = max(maxim,cnt);
            }
        }
        return maxim;
    }
};