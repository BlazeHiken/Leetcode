class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        for(int i=0; i<score.size(); i++) {
            pq.push(score[i]);
        }
        unordered_map<int,string> mp;

        mp[pq.top()] = "Gold Medal";
        pq.pop();
        if(!pq.empty()) {
            mp[pq.top()] = "Silver Medal";
            pq.pop();
        }
        if(!pq.empty()) {
            mp[pq.top()] = "Bronze Medal";
            pq.pop();
        }
        int counter = 4;
        while(!pq.empty()) {
            mp[pq.top()] = to_string(counter++);
            pq.pop();
        }
        vector<string> ans;
        for(int i=0; i<score.size(); i++) {
            ans.push_back(mp[score[i]]);
        }
        return ans;
    }
};