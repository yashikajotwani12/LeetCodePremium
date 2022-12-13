The doubly linked list works in a similar way but has one more reference field which is known as the "prev" field. With this extra field, you are able to know the previous node of the current node.

// Definition for doubly-linked list.
struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};