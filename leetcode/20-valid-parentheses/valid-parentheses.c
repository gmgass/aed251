bool isValid(char* s) {
    int sSize = strlen( s );

    typedef struct Stack {
        char bracket[sSize];
        int top;
    } Stack_t;

    Stack_t p;
    p.top = -1;

    for ( int i = 0; i < sSize; i++ ) {
        char sBracket = s[i];

        if ( sBracket == '(' || sBracket == '[' || sBracket == '{' ) {
            p.bracket[++p.top] = sBracket;
        } else {
            if ( p.top == -1 ||
               ( sBracket == ')' && p.bracket[p.top] != '(' ) || 
               ( sBracket == ']' && p.bracket[p.top] != '[' ) || 
               ( sBracket == '}' && p.bracket[p.top] != '{' )) {
                return false;
            }
            p.top--;
        }
    }

    return p.top == -1;
}