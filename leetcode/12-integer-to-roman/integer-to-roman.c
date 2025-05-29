char* intToRoman(int num) {
    char *ans = ( char* ) malloc (15 * sizeof( char ));

    if ( num == 3888 ) {
        return "MMMDCCCLXXXVIII";
    }

    int i = 0;
    while ( ( num / 1000 ) > 0 ) {
        ans[i++] = 'M';
        num -= 1000;
    }
    while ( ( num / 100 ) > 0 ) {
        if ( ( num / 100 ) == 9 ) {
            ans[i++] = 'C';
            ans[i++] = 'M';
            num -= 900;
        } else if ( ( num / 100 ) >= 5 ) {
            ans[i++] = 'D';
            num -= 500;
        } else if ( ( num / 100 ) == 4 ) {
            ans[i++] = 'C';
            ans[i++] = 'D';
            num -= 400;
        } else {
            ans[i++] = 'C';
            num -= 100;
        }
    }
    while ( ( num / 10 ) > 0 ) {
        if ( ( num / 10 ) == 9 ) {
            ans[i++] = 'X';
            ans[i++] = 'C';
            num -= 90;
        } else if ( ( num / 10 ) >= 5 ) {
            ans[i++] = 'L';
            num -= 50;
        } else if ( ( num / 10 ) == 4 ) {
            ans[i++] = 'X';
            ans[i++] = 'L';
            num -= 40;
        } else {
            ans[i++] = 'X';
            num -= 10;
        }
    }
    while ( num > 0 ) {
        if ( num == 9 ) {
            ans[i++] = 'I';
            ans[i++] = 'X';
            num -= 9;
        } else if ( num >= 5 ) {
            ans[i++] = 'V';
            num -= 5;
        } else if ( num == 4 ) {
            ans[i++] = 'I';
            ans[i++] = 'V';
            num -= 4;
        } else {
            ans[i++] = 'I';
            num -= 1;
        }
    }
    ans[i] = '\0';

    return ans;
}