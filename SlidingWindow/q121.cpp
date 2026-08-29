class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX, maxProf=0;
        for(int i=0; i<prices.size(); i++) {
            minPrice = min(prices[i],minPrice);
            maxProf = max(prices[i]-minPrice,maxProf);
        }
        return maxProf;
    }
};