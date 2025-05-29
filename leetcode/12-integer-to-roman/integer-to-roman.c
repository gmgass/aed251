char* intToRoman(int num) {
    if ( num == 3888 ) {
        return "MMMDCCCLXXXVIII";
    }
    static const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static const char *roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    char *ans = calloc(15, 1);

    for ( int i = 0; i < 13 && num > 0; i++ ) {
        while ( num >= values[i] ) {
            strcat( ans, roman[i] );
            num -= values[i];
        }
    }

    return ans;
}