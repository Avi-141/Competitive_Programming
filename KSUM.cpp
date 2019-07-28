class Solution {
private:
    const int K = 4;
    int size = 0;
    void search(vector<int>& nums, int pos, int k, int target, vector<int>& v, vector<vector<int>>& vv)
    {
        if(k == 2)
        {
            int l = pos, r = size-1;
            while(l < r)
            {
                int t = nums[l]+nums[r];
                if(t > target) r--;
                else if(t < target) l++;
                else 
                {
                    v[K-2] = nums[l++];
                    v[K-1] = nums[r--];
                    vv.push_back(v);
                    while(l<r && nums[l]==nums[l-1]) l++; //avoid duplicates;
                    while(l<r && nums[r]==nums[r+1]) r--; //avoid duplicates;
                }
            }
        }
        else
        {
            for(int top = size-k; pos <= top; ++pos)
            {
                int sum = 0;
                for(int i = 0; i < k; i++) sum += nums[pos+i]; 
                if(sum > target) break; //avoid futile searching;
                sum = nums[pos];
                for(int i = 0; i < k-1; ++i) sum += nums[size-1-i];
                if(sum < target) continue; //avoid futile searching;
                v[K-k] = nums[pos];
                search(nums, pos+1, k-1, target-nums[pos], v, vv);
                while(pos<=top && nums[pos+1]==nums[pos]) pos++; //avoid duplicates;
            }
        }
    }
public:
    //AC - 16ms - handle kSum;
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        size = nums.size();
        vector<vector<int>> vv;
        vector<int> v(K, 0);
        search(nums, 0, K, target, v, vv);
        return vv;
    }
};