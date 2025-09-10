public class Solution {
    public int MaximumWealth(int[][] accounts) {
        int result = 0;

        foreach (int[] row in accounts) {
            int sum = 0;

            foreach (int column in row) {
                sum += column;
            }

            result = Math.Max(result, sum);
        }

        return result;
    }
}