class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<array<int,3>> digisum;
        array<int,3> temp;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            int sum = 0;
            while(num>0) {
                sum += num%10;
                num/=10;
            }
            digisum.push_back({sum,nums[i],i});
        }
        sort(digisum.begin(),digisum.end());
        int swaps = 0;
        for(int i=0; i<nums.size(); i++) {
            while(digisum[i][2]!=i) {
                int idx = digisum[i][2];
                temp = digisum[i];
                digisum[i] = digisum[idx];
                digisum[idx] = temp;
                swaps++;
            }
        }
        return swaps;
    }
};