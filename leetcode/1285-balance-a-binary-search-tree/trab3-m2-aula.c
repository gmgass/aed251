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

void inOrder ( struct TreeNode *root, int i ) {
    if ( !root ) return;

    inOrder( root->left, i );
    arr[i++] = root->val;
    inOrder( root->right, i );    
}

struct TreeNode *arrayToBalancedBST ( struct TreeNode *root, int *arr, int start, int end ) {
    /*
    int *left // Ponteiro do começo
    int *right // Ponteiro do fim

    int mid = start ( end - start ) / 2; // Elemento central para recursão

    root->val = mid;

    arrayToBalancedBST ( root, arr, start, mid )
    arrayToBalancedBST ( root, arr, mid + 1, end )
    */
}

struct TreeNode *balanceBST( struct TreeNode *root ) {
    // Primeiro conto a quantidade de nós na árvore para criar um vetor de mesmo tamanho.
    int arrSize = countNodes ( root );
    int *arr = ( int* ) malloc( sizeof( int ) * arrSize );
    int i = 0; // Esse i posso mover pra dentro da função inOrder e usar arrSize-1 pro elemento final do vetor.

    // Em seguida, preencho o vetor de forma ordenada.
    inOrder( root, i );

    // A partir daqui, sei que, com um vetor ordenado, posso reconstruir a árvore de forma balanceada.
    // Contudo, não me lembro exatamente como é feito esse processo.
    int start = arr[0];
    int end = arr[i];

    arrayToBalancedBST ( root, arr, start, end );
    return struct TreeNode *root;
}
