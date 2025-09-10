class Solution {
    public int maximumWealth(int[][] accounts) {
        int result = 0;

        for ( int[] row : accounts ) {  // row == costumers
            int sum = 0;

            for ( int column : row ) {  // col == money in each costumers' account
                sum += column;
            }
            
            result = Math.max(result, sum);
        }

        return result;
    }
}