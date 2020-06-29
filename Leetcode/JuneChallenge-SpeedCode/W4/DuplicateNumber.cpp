class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]]; //finding a cycle
            if(fast==slow)
                break;
        }
        fast=0;
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return fast;
    }
};