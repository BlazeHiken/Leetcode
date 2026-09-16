class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k1;

    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for(auto& num : nums) {
            pq.push(num);
        }
        while(pq.size()>k1) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k1) pq.pop();
        return pq.top();
    }
};