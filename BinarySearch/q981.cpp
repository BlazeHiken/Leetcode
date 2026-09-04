class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        auto &v = mp[key]; //reuse vector without hash lookup everytime
        if(v[0].first>timestamp) return "";
        int low=0,high=v.size()-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(v[mid].first==timestamp) {
                return v[mid].second;
            }
            if(v[mid].first>timestamp) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return v[high].second;
    }
};
