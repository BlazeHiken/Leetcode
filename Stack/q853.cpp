class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> ans;
        int fleets = 0;
        double maxtime=-1.0;
        for(int i=0; i<speed.size(); i++) {
            ans.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        sort(ans.rbegin(),ans.rend());
        for(int i=0; i<speed.size(); i++) {
            if(ans[i].second > maxtime) {
                maxtime = ans[i].second;
                fleets++;
            }
        }
        return fleets;
    }
};