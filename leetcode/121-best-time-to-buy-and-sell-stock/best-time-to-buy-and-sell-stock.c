int maxProfit(int* n, int pricesSize) {
    int profit = 0;
    int buy = 0;
    
    for ( int sell = 1; sell < pricesSize; sell++ ) {
        if ( n[sell] <= n[buy] ) {
            buy = sell;
        } else {
            profit = fmax( profit, ( n[sell] - n[buy] ));
        }
    }

    return profit;
}