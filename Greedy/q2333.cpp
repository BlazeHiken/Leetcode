class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = k1+k2;
        int n = nums1.size();
        vector<long long> diff(n);
        long long total = 0;
        for(int i=0; i<n; i++) {
            diff[i]=abs(nums1[i]-nums2[i]);
            total+=diff[i];
        }
        if(k>=total) return 0;
        sort(diff.begin(),diff.end(),greater<long long>());
        for(int i=0; i<n; i++) {
            long long next;
            if(i+1<n) {
                next = diff[i+1];
            } else {
                next = 0;
            }
            long long count=i+1;
            long long cost=count*(diff[i]-next);
            if(k>=cost) {
                k-=cost;
            } else {
                long long levels = k/count;
                long long remainder = k%count;
                long long target = diff[i]-levels;
                long long sum = 0;
                for(int j=0; j<=i; j++) {
                    long long d=target;
                    if(j<remainder) {
                        d--;
                    }
                    sum+=d*d;
                }
                for(int j=i+1; j<n; j++) {
                    sum += diff[j]*diff[j];
                }
                return sum;
            }
        }
        return 0;
    }
};