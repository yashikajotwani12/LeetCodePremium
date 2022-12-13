/* Let's briefly review the structure definition of a node in the singly linked list.

// Definition for singly-linked list. */

struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

1. Initiate a new linked list: represent a linked list using the head node.

class MyLinkedList {
private:
    SinglyListNode *head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
};


2. Traverse the linked list to get element by index.

/** Helper function to return the index-th node in the linked list. */
SinglyListNode* getNode(int index) {
    SinglyListNode *cur = head;
    for (int i = 0; i < index && cur; ++i) {
        cur = cur->next;
    }
    return cur;
}
/** Helper function to return the last node in the linked list. */
SinglyListNode* getTail() {
    SinglyListNode *cur = head;
    while (cur && cur->next) {
        cur = cur->next;
    }
    return cur;
}
/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int get(int index) {
    SinglyListNode *cur = getNode(index);
    return cur == NULL ? -1 : cur->val;
}


3. Add a new node.

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void addAtHead(int val) {
    SinglyListNode *cur = new SinglyListNode(val);
    cur->next = head;
    head = cur;
    return;
}

/** Append a node of value val to the last element of the linked list. */
void addAtTail(int val) {
    if (head == NULL) {
        addAtHead(val);
        return;
    }
    SinglyListNode *prev = getTail();
    SinglyListNode *cur = new SinglyListNode(val);
    prev->next = cur;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void addAtIndex(int index, int val) {
    if (index == 0) {
        addAtHead(val);
        return;
    }
    SinglyListNode *prev = getNode(index - 1);
    if (prev == NULL) {
        return;
    }
    SinglyListNode *cur = new SinglyListNode(val);
    SinglyListNode *next = prev->next;
    cur->next = next;
    prev->next = cur;
}


5. Delete a node.


/** Delete the index-th node in the linked list, if the index is valid. */
void deleteAtIndex(int index) {
    SinglyListNode *cur = getNode(index);
    if (cur == NULL) {
        return;
    }
    SinglyListNode *next = cur->next;
    if (index == 0) {
        // modify head when deleting the first node.
        head = next;
    } else {
        SinglyListNode *prev = getNode(index - 1);
        prev->next = next;
    }
}