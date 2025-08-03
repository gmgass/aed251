#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void freeTree( struct TreeNode *root ) {
    if ( !root ) return;

    freeTree( root->left );
    freeTree( root->right );
    free( root );
}

struct TreeNode *generateTree( int current, int max ) {
    if ( current > max ) return NULL;

    struct TreeNode *node = ( struct TreeNode* ) malloc( sizeof( struct TreeNode ));
    if ( !node ) exit( 1 );

    node->val = current;
    node->left = NULL;
    node->right = generateTree( current + 1, max );

    return node;
}

void printTree(struct TreeNode* root, int space) {
    if ( !root ) return;
    
    space += 5;
    
    printTree( root->right, space );

    printf( "\n" );
    for ( int i = 5; i < space; i++ ) printf( " " );
    printf( "%d\n", root->val );

    printTree( root->left, space );
}

int countNodes ( struct TreeNode *root );
void inOrder ( struct TreeNode *root, int *arr, int *i );
struct TreeNode *arrayToBalancedBST ( struct TreeNode *root, int *arr, int start, int end );
struct TreeNode *balanceBST( struct TreeNode *root );

int main() {
    struct TreeNode *root = generateTree( 1, 4 );
    printTree( root, 0 );

    struct TreeNode *newRoot = balanceBST( root );
    printTree( newRoot, 0 );

    freeTree( root );
    freeTree( newRoot );
    
    return 0;
}




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

    int mid = start + ( end - start ) / 2;

    struct TreeNode *node = ( struct TreeNode* ) malloc ( sizeof( struct TreeNode ));
    if ( !node ) return NULL;

    node->val = arr[mid];
    node->left = arrayToBST( arr, start, mid - 1 );
    node->right = arrayToBST( arr, mid + 1, end );

    return node;
}

struct TreeNode *balanceBST( struct TreeNode *root ) {
    if ( !root ) return NULL;

    // Primeiro conto a quantidade de nós na árvore para criar um vetor de mesmo tamanho.
    int arrSize = countNodes ( root );
    int *arr = ( int* ) malloc( sizeof( int ) * arrSize );
    if ( !arr ) return NULL;

    int i = 0;

    // Em seguida, preencho o vetor de forma ordenada.
    inOrder( root, arr, &i );

    // Por fim, construo uma árvore balanceada a partir do vetor ordenado.
    struct TreeNode *newRoot;
    newRoot = arrayToBST( arr, 0, arrSize - 1 );

    free( arr );

    return newRoot;
}
