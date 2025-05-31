int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    for ( int i = 0; i < numsSize; i++ ) {
        if ( count == 0 ) {
            candidate = nums[i];
        }
        nums[i] == candidate ? count++ : count--;
    }

    return candidate;
}