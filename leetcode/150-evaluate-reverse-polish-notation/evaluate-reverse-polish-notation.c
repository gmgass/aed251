int evalRPN(char **tokens, int tokensSize) {
    typedef struct Stack {
        int item[tokensSize];
        int top;
    } Stack;

    Stack nums;
    nums.top = -1;

    for ( int i = 0; i < tokensSize; i++ ) {
        char *token = tokens[i];

        if ( strcmp( token, "+" ) == 0 ) {
            int b = nums.item[nums.top--];
            int a = nums.item[nums.top--];
            nums.item[++nums.top] = a + b;
        } else if ( strcmp( token, "-" ) == 0 ) {
            int b = nums.item[nums.top--];
            int a = nums.item[nums.top--];
            nums.item[++nums.top] = a - b;
        } else if ( strcmp( token, "*" ) == 0 ) {
            int b = nums.item[nums.top--];
            int a = nums.item[nums.top--];
            nums.item[++nums.top] = a * b;
        } else if ( strcmp( token, "/" ) == 0 ) {
            int b = nums.item[nums.top--];
            int a = nums.item[nums.top--];
            nums.item[++nums.top] = a / b;
        } else {
            nums.item[++nums.top] = atoi( token );
        }
    }

    return nums.item[nums.top];
}