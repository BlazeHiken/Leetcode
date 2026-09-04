class Solution {
public:
    bool canFinish(vector<int>& piles,int k,int h) {
        long long hrs=0;
        for(int i=0; i<piles.size(); i++) {
            hrs += (piles[i] + k - 1)/k;
            if(hrs>h) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high = *max_element(piles.begin(), piles.end()); //here these are speeds not indexes
        int n = piles.size();
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(canFinish(piles,mid,h)) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return low;
    }

};
