class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bits=0;
            int mask=1<<i;
            for(auto num:nums){
                if(num&mask)
                    bits++;
            }
            if(bits%3)
                ans|=mask;
        }
        return ans;
    }
};