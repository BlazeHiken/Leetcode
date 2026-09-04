class Solution {
public:
    // read the note

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) { 
            swap(nums1, nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int leftSize = (m+n+1)/2;
        int low=0,high=m;
        while(low<=high) {
            int partitionA = low +(high-low)/2;
            int partitionB = leftSize - partitionA;
            int leftA = (partitionA == 0)? INT_MIN : nums1[partitionA-1];
            int leftB = (partitionB == 0)? INT_MIN : nums2[partitionB-1];
            int rightA = (partitionA == nums1.size())? INT_MAX : nums1[partitionA];
            int rightB = (partitionB == nums2.size())? INT_MAX : nums2[partitionB];
            
            if(leftA <= rightB && leftB <= rightA) {
                int leftmax = max(leftA,leftB);
                int rightmin = min(rightA,rightB);
                if((m+n)%2==0) {
                    return (double)(leftmax+rightmin)/2;
                } else {
                    return leftmax;
                }
            }
            if(leftA > rightB) {
                high = partitionA-1;
            } else if(leftB > rightA) {
                low = partitionA+1;
            }
        }
        return 0;
    }
};
/*
we binary search how many elements in nums 1 exist in the left side of the conceptual merged array

swap because we binary search on nums1, it should be smaller or nums2 gets out of bounds
let sizes be m and n

for a median, we find how many elements at its left side inclusive of the median. this is for both arr combined
so its (m+n+1)/2 on the left always, we call it as leftsize

partition is not an index, it is the number of elements of that array in the left side of conceptual merged arr
if partA+partB is leftsize, we only calculate part A and get partB by leftsize-partA
partitions can become 0 or size ie number of elements on the left can be 0 or all ele
because its not an index, so using it as an index fails by out of bounds, if partA is 0 then partB is n, if partA is m then partB is 0

for a correct cut/partition, obviously max of left in nums1 should be <= min of right in nums2 and vice versa
if leftA > rightB, it means that ele in nums1 isnt supposed to be in the left, so we high = partA-1
if leftB > rightA, it means the ele in nums1 should be in the left, so we low=partA+1

if odd, we return leftmax of merged arr which is max(leftA,leftB)
if even, we average leftmax and rightmin and return

return 0 at the end just for the compiler, its unreachable
*/
