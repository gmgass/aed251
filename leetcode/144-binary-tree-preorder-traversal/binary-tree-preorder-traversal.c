/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * }; // Note: The returned array must be malloced, assume caller calls free().
 */

void preOrder( struct TreeNode *root, int *ans, int *returnSize ) {
    if ( !root ) return;

    ans[ *returnSize ] = root->val;
    ( *returnSize )++;

    preOrder( root->left, ans, returnSize );
    preOrder( root->right, ans, returnSize );

}

int* preorderTraversal( struct TreeNode *root, int *returnSize ) {
    int *ans = (int*) malloc( sizeof( int ) * 100 );
    *returnSize = 0;

    preOrder( root, ans, returnSize );

    return ans;
}