/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int verify( struct TreeNode* root ) {
    if ( !root ) return 0;

    int leftHeight;
    int rightHeight;

    leftHeight = verify( root->left );
    if ( leftHeight == -1 ) return -1;

    rightHeight = verify( root->right );
    if ( rightHeight == -1 ) return -1;

    if ( abs( leftHeight - rightHeight ) < 2 ) {
        return fmax( leftHeight, rightHeight ) + 1;
    } else {
        return -1;
    }
}

bool isBalanced(struct TreeNode* root) {
    return verify( root ) != -1;
}