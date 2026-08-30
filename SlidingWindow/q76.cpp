class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int minL;
        int ans=INT_MAX;

        for(int i=0; i<t.size(); i++) {
            need[t[i]]++;
        }
        int req=0;

        int l=0;
        for(int r=0; r<s.size(); r++) {
            window[s[r]]++;
            //use count because checking key that doesnt exist creates key and the size changes
            if(need.count(s[r]) && window[s[r]]==need[s[r]]) { 
                req++;
            }
            while(req==need.size()) {
                if(r-l+1 < ans) {
                    ans = r-l+1;
                    minL = l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]]<need[s[l]]) {
                    req--;
                }   
                l++;
            }
        }

        if(ans == INT_MAX) {
            return "";
        }
        return s.substr(minL,ans);
    }
};