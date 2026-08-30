class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int l=0;
        int r=s1.size()-1;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0; i<s1.size(); i++) {
            freq1[s1[i]-'a']++;
        }
        for(int i=0; i<=r; i++) {
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2) return true;

        for(int r=s1.size(); r<s2.size(); r++) {
            freq2[s2[r]-'a']++;
            freq2[s2[l]-'a']--;
            l++;
            if(freq1==freq2) return true;
        }
        return false;
    }
};