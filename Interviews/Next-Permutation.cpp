void Solution::nextPermutation(vector<int> &nums) {
   int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) 
        {
            reverse(nums.begin(), nums.end());
        }
        else {
            for (l = n - 1; l > k; l--) 
            {
                if (nums[l] > nums[k]) 
                {
                    break;
                }
            } 
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
/*void Solution::nextPermutation(vector<int> &A) {
    
    int i,j;
    int n = A.size();
    for(i = n - 2;i >= 0;i --)
    {
        if(A[i] < A[i + 1])
            break;
    }
    if(i == -1)
    {
        reverse(A.begin(),A.end());
        return ;
    }
    
    for(j = n - 1;j > i;j --)
    {
        if(A[j] > A[i])
            break;
    }
    swap(A[j],A[i]);
    reverse(A.begin() + i + 1,A.end());
    return ;
}
*/