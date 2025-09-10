// Language-Integrated Query solution (probably slower)

public class Solution {
    public int MaximumWealth(int[][] accounts) {
        return accounts.Select( costumerAccounts => costumerAccounts.Sum() ).Max();
    }
}