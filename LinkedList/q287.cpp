class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,tmp=0,fast=0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        } 
        while(tmp!=slow) {
            slow = nums[slow];
            tmp = nums[tmp];
        }
        return tmp;
    }
};

/* turn the array to linked list
where index is the node and value is node->next
eg nums = [1,3,4,2,2]
so,
nums[0]->next = 1
nums[1]->next = 3
nums[3]->next = 2
nums[2]->next = 4
nums[4]->next = 2

therefore linked list is
0 -> 1 -> 3 -> 2 <--> 4
the start of the cycle is the repeated digit
*/