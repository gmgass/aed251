char* longestCommonPrefix(char** strs, int strsSize) {
    for ( int c = 0; ; c++ ) {
        if ( strs[0][c] == '\0' ) {
            return strs[0];
        }
        for ( int w = 1; w < strsSize; w++ ) {
            if ( strs[0][c] != strs[w][c] ) {
                strs[0][c] = '\0';
                return strs[0];
            }
        }
    }
}