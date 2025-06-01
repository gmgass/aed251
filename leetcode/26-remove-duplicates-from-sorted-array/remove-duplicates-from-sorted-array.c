int removeDuplicates(int* n, int numsSize) {
    int i = 0;
    
    for ( int j = 0; j < numsSize; j++ ) {
        if ( n[i] != n[j] ) {
            n[++i] = n[j];
        }
    }

    return ( i + 1 );
}