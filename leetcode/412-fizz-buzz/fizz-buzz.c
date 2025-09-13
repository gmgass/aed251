/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char **answer = NULL;
    answer = (char**)malloc(n * sizeof(char*));

    int i = 1;
    while ( i <= n ) {
        if ( i % 15 == 0) { 
            answer[i - 1] = "FizzBuzz";
        } else if ( i % 3 == 0 ) {
            answer[i - 1] = "Fizz";
        } else if ( i % 5 == 0 ) {
            answer[i - 1] = "Buzz";
        } else {
            char buffer[6];
            sprintf( buffer, "%d", i );
            answer[i - 1] = strdup( buffer );
        }
        i++;
    }

    return answer;
}