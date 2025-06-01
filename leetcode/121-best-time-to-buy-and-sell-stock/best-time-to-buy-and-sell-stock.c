int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int buyPrice = prices[0];

    for ( int i = 1; i < pricesSize; i++ ) {
        if ( buyPrice > prices[i] ) {
            buyPrice = prices[i];
        } else {
            int profit = prices[i] - buyPrice;
            if ( profit > maxProfit ) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}