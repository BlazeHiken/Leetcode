class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<int> freq(101,0);//freq vect
        int distinct;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) { //start index of subarr
            distinct = 0;
            for(int j=i; j<nums.size(); j++) { //last index of subarr
                if(freq[nums[j]]==0) { //distinct found
                    distinct++;
                }
                freq[nums[j]]++;
                sum += distinct*distinct;
            }
            for (int j=i; j<nums.size(); j++) { //reset vector but fast
                freq[nums[j]] = 0;
            }
        }
        return sum;
    }
};