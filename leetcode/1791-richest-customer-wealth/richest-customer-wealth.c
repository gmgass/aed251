// attempts: 2
// Forgot the Col parameter was a pointer
// Got the row and column order wrong

// Time complexity = O(m * n)
// Space complexity = O(1)

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int result = 0;

    for (int i = 0; i < accountsSize; i++) {
        int sum = 0;

        for (int j = 0; j < *accountsColSize; j++) {
            sum += accounts[i][j];
        }

        if (sum > result) result = sum;
    }

    return result;
}