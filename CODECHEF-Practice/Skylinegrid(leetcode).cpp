class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] horizontal = new int[grid[0].length];
        int[] vertical = new int[grid.length];
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){
                horizontal[j]=Math.max(horizontal[j],grid[i][j]);
                vertical[i]=Math.max(vertical[i],grid[i][j]);
            }
        }
        int res = 0;
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){
                res+=Math.min(horizontal[j],vertical[i]) - grid[i][j];
            }
        }
        return res;
    }
}