/* struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes ( struct TreeNode *root ) {
    if ( !root ) return 0;
    return 1 + countNodes( root->left ) + countNodes( root ->right );
}

void inOrder ( struct TreeNode *root, int *arr, int *i ) {
    if ( !root ) return;

    inOrder( root->left, arr, i );
    arr[ (*i)++ ] = root->val;
    inOrder( root->right, arr, i );    
}

struct TreeNode *arrayToBST ( int *arr, int start, int end ) {
    if ( start > end ) return NULL; 
    
    int mid = start + ( end - start ) / 2; // "mid = (start + end) / 2" pode causar overflow.

    struct TreeNode *node = ( struct TreeNode* ) malloc( sizeof( struct TreeNode ));
    node->val = arr[ mid ];
    node->left = arrayToBST( arr, start, mid - 1 ); // 30min preso num stack overflow porque esqueci do "-1".
    node->right = arrayToBST ( arr, mid + 1, end );
    
    return node;
}

struct TreeNode *balanceBST( struct TreeNode *root ) {
    if ( !root ) return NULL; // Tinha esquecido dessa verificação.

    // Primeiro conto a quantidade de nós na árvore para criar um vetor de mesmo tamanho.
    int arrSize = countNodes ( root );
    int *arr = ( int* ) malloc( sizeof( int ) * arrSize );
    int i = 0; // Não posso declarar dentro de uma função recursiva.

    // Em seguida, preencho o vetor de forma ordenada.
    inOrder( root, arr, &i ); // Tinha esquecido de passar o arr como parametro e de colocar o &.

    // Por fim, construo uma nova árvore balanceada a partir do vetor ordenado.
    struct TreeNode *newRoot;
    newRoot = arrayToBST ( arr, 0, arrSize - 1 );

    free( arr );
    return newRoot;
}
