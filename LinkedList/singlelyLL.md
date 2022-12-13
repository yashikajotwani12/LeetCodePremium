Each node in a singly-linked list contains not only the value but also a reference field to link to the next node. By this way, the singly-linked list organizes all the nodes in a sequence.

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};