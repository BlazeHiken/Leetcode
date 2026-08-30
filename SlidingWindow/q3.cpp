class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        unordered_map<char,int> map;

        for (int r = 0; r<s.size(); r++) {
            if(map.count(s[r])) {
                l = max(l,map[s[r]]+1);
            }

            map[s[r]] = r;
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};