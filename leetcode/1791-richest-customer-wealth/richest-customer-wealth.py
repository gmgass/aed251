class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        result = 0

        for costumerAccounts in accounts:
            costumerSum = sum( costumerAccounts )

            if costumerSum > result:
                result = costumerSum
        
        return result
        