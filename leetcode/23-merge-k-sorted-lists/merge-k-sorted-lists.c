// REFAZER esse leetcode futuramente tanto com mergeSort quanto quickSort.

struct ListNode* mergeTwoLists( struct ListNode* l1, struct ListNode* l2 ) {
    struct ListNode temp;
    temp.next = NULL;
    struct ListNode* end = &temp;

    while ( l1 && l2 ) {
        if ( l1->val <= l2->val ) {
            end->next = l1;
            l1 = l1->next;
        } else {
            end->next = l2;
            l2 = l2->next;
        }
        end = end->next;
    }

    end->next = ( l1 != NULL ) ? l1 : l2;
    return temp.next;
}

struct ListNode* recursiveMerge( struct ListNode** lists, int start, int end ) {
    if ( start == end ) {
        return lists[start];
    }

    int mid = start + ( end - start ) / 2;
    struct ListNode* l1 = recursiveMerge( lists, start, mid);
    struct ListNode* l2 = recursiveMerge( lists, mid + 1, end );

    return mergeTwoLists( l1, l2 );
}

struct ListNode* mergeKLists( struct ListNode** lists, int listsSize ) {
    if ( listsSize == 0 ) return NULL;

    return recursiveMerge( lists, 0, listsSize - 1);
}