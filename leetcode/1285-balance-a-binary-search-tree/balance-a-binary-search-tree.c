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

    void freeTree( struct TreeNode *root ) {
        if ( !root ) return;

        freeTree( root->left );
        freeTree( root->right );
        free( root );
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
        freeTree( root );

        return newRoot;
    }
