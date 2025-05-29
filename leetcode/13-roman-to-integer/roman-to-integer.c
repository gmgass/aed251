int charToInt( char c ) {
    switch( c ) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int res = 0;

    for ( int i = 0; i < strlen( s ); i++ ) {
        int current = charToInt( s[i] );
        int next = charToInt( s[i + 1] );

        if ( current < next ) {
            res += next - current;
            i++;
        } else {
            res += current;
        }
    }

    return res;
}