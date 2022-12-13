Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

1. MyLinkedList() Initializes the MyLinkedList object.
2. int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
3. void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
4. void addAtTail(int val) Append a node of value val as the last element of the linked list.
5. void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
6. void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.


Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3




class MyLinkedList {
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        
    }
    
    void addAtHead(int val) {
        
    }
    
    void addAtTail(int val) {
        
    }
    
    void addAtIndex(int index, int val) {
        
    }
    
    void deleteAtIndex(int index) {
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


class Node {
    public:
    int val;
    Node* next;
    // Constructor of Node
    Node(int x): val(x), next(nullptr) {}
	// Above code is equivalent to the below code
	// Node(int x) { val=x; next=nullptr;}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    // Constructor
    MyLinkedList(): head(nullptr), size(0) {}
	// Above code is equivalent to the below code
	// MyLinkedList() { head=nullptr; size=0;}
	
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // Return -1 for invalid index
        if(index>=size || index < 0) {
            return -1;
        }
        Node* current=head;
        for(int i=0;i<index;++i) {
            current= current->next;
        }
        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);       
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // Return if invalid index
        if (index>size || index < 0) {
            return;
        }
        Node* current= head;
        Node* new_node = new Node(val);
        // index == 0 implies insert at head
        // Considered separately as we need to update head
        if (index == 0) {
            new_node->next = current;
            // Update head
            head = new_node;
        }
        else {
            // Run loop till index-1 as we need to insert node at index
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }
            /* 
                current --> current->next
                            /
                        new_node
                        
                current    current->next
                      \      /
                        new_node           
            
            */            
            new_node->next = current->next;
            current->next = new_node;
        }
        // Increase size whenever we insert node
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // Return if invalid index
        if(index>=size || index < 0) {
            return;
        }
        // index==0 implies delete at head
        // Considered separately as we need to update head
        if (index == 0) {
            Node* nextNode = head->next;
            // Always remember to free memory to prevent memory leak
            delete head;
            head = nextNode;            
        }
        else {
            Node* current= head;
            // Run loop till index-1 as we need to insert node at index
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }
            /* 
                current --> current->next --> current->next->next
                                                (next_node)
                        
                current --> DELETED --> current->next->next
                
                current --> next_node
            
            */  
            Node* nextNode = current->next->next;
            // Always remember to free memory to prevent memory leak
            delete current->next;
            current->next = nextNode;
        }
        // Decrease size whenever we delete node
            size--;
    }
    /*
        Default destructor only deletes head and size (allocated by constructor)
        We need destructor to free the memory used by all individual nodes
    */
    // Destructor
    ~MyLinkedList()
    {
        Node *p = head;
        // Delete node at head while head is not null
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */