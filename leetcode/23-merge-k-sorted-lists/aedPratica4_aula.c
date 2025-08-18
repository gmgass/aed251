// GUSTAVO MORAES GASS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    OK. Como vou abordar esse problema?
    - Fazer merge de duas listas
    - Usar recursão para chamar quantas listas forem necessárias
*/

/*struct ListNode* createNode( int val ) {
    struct ListNode* newNode = ( struct ListNode* ) malloc( sizeof ( struct ListNode ));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}
*/

struct ListNode* merge( struct ListNode* l1, struct ListNode* l2 ) {
    struct ListNode temp;
    struct ListNode* end = &temp;

    while ( l1 && l2 ) {
        if ( l1->val < l2->val ) {
            end->next = l1;
        } else {
            end->next = l2;
            l2 = l2->next;
        }
        end = end->next;
    }
    if ( l1 != NULL ) {
        end->next = l1;
    } else {
        end->next = l2;
    }

    return temp.next;
}

struct ListNode* recursiveMerge( struct ListNode** lists, int left, int right ) {
    if ( start == end ) {
        return lists[left];
    }

    int mid = start ( end - start ) / 2;
    struct ListNode* l1 = merge( lists, left, mid - 1 );
    struct ListNode* l2 = merge( lists, mid + 1, right );

    return MergeTwo( l1, l2 );
}

struct ListNode* mergeKLists( struct ListNode** lists, int listsSize ) {
    struct ListNode* ans;
    ans = recursiveMerge( lists, 0, listsSize - 1);

    return ans;
}