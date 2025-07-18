int maxChunksToSorted(int* arr, int arrSize) {
    int* prefixMax = ( int* ) malloc( arrSize * sizeof( int ));
    int* suffixMin = ( int* ) malloc( arrSize * sizeof( int ));

    for ( int i = 0; i < arrSize; i++ ) {
        prefixMax[i] = arr[i];
        suffixMin[i] = arr[i];
    }

    for ( int i = 1; i < arrSize; i++ ) {
        prefixMax[i] = fmax( prefixMax[i], prefixMax[i - 1] );
    }

    for ( int i = arrSize - 2; i >= 0; i-- ) {
        suffixMin[i] = fmin( suffixMin[i], suffixMin[i + 1] );
    }

    int chunks = 1;
    for ( int i = 1; i < arrSize; i++ ) {
        if ( suffixMin[i] > prefixMax[i - 1] ) chunks++;
    }

    return chunks;
}