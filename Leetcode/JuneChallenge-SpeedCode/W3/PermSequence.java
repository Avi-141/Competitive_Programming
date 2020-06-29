class Solution {
   public String getPermutation(int n, int k) {
    
    List<Integer> nums = new LinkedList();
    StringBuilder res = new StringBuilder();

    int[] f = new int[n];
    f[0] = 1;          

    for(int i = 1; i < n; i++){
      nums.add(i);
      f[i] = f[i - 1] * i;
    }
    nums.add(n);

    k--;  // 0 based indexing


    for(int i = n; i > 0; i--){
      int idx = k / f[i - 1]; //index of num + perm(remaining)
      k = k % f[i - 1]; //remaining perms 

      res.append(nums.get(idx));
      nums.remove(idx);
    }
    return res.toString();
 }
}