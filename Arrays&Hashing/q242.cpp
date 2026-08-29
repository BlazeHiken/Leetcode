class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        for(char ch : t) {
            if(--mp[ch]<0){
                return false;
            }
        }
        return true;
        */
        if(s.size()!=t.size()) return false;
        vector<int> freq(26,0); //arrays are always faster than maps cuz no hashing, so array of size 26 is better but worse for bigger sizes
        for(char ch : s) {
            freq[ch-'a']++;
        }
        for(char ch : t) {
            if(--freq[ch-'a']<0){
                return false;
            }
        }
        return true;

    }
};