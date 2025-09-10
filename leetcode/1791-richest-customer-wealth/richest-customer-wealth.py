# "Pythonic" way to solve: concise and readable

class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        return max( sum(costumerAccounts) for costumerAccounts in accounts )
        