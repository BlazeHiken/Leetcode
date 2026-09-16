class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;
        for(auto& point : points) {
            int x = point[0];
            int y = point[1];
            pq.push({x*x+y*y,x,y});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()) {
            vector<int> pt = pq.top();
            pq.pop();
            ans.push_back({pt[1],pt[2]});
        }
        return ans;
    }
};