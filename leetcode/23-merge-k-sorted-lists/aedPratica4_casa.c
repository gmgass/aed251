#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists( struct ListNode* l1, struct ListNode* l2 ) {
    struct ListNode temp;
    temp.next = NULL;
    struct ListNode* end = &temp;

    while ( l1 && l2 ) {
        if ( l1->val <= l2->val ) {
            end->next = l1;
            l1 = l1->next;              // Esqueci repetidamente de avançar l1.
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

    return recursiveMerge( lists, 0, listsSize - 1 );
}



// === FUNÇÕES PARA TESTE ==========================================================================
struct ListNode* createList(int* arr, int n) {
    if (n == 0) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    struct ListNode* list1 = createList(arr1, 3);
    struct ListNode* list2 = createList(arr2, 3);
    struct ListNode* list3 = createList(arr3, 2);

    struct ListNode* lists[3] = {list1, list2, list3};

    struct ListNode* result = mergeKLists(lists, 3);

    printf("Lista mesclada: ");
    printList(result);

    return 0;
}