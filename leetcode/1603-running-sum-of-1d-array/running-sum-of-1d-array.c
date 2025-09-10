// attempts: 3
// forgot the returnSize
// forgot to malloc the runningSum array

// Time complexity = O(n)
// Space complexity = O(n)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* runningSum = (int*)malloc(numsSize * sizeof(int));
    runningSum[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        runningSum[i] = runningSum[i - 1] + nums[i];
    }

    return runningSum;
}