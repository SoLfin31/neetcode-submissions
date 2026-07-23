class MyLinkedList {

    struct ListNode{
        public:
            int val;
            ListNode* prev;
            ListNode* next;
        ListNode() : val{0}, prev{nullptr}, next{nullptr} {}
        ListNode(int x) : val{x}, prev{nullptr}, next{nullptr} {} 
    };

public:
    MyLinkedList() {
        len = 0;
        left_node = new ListNode();
        right_node = new ListNode();

        left_node->next = right_node;
        left_node->prev = nullptr;
        right_node->prev = left_node;
        right_node->next = nullptr;
        

    }
    
    ListNode* left_node;
    ListNode* right_node;
    int len;
    
    int get(int index) {
        if (index >= len)    {return -1;}

        ListNode* cur = left_node->next;
        while(index > 0)
        {
            cur = cur->next;
            index -= 1;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* tem = left_node->next;
        left_node->next = newNode;
        newNode->next = tem;
        newNode->prev = left_node;
        tem->prev = newNode;
        len += 1;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* tem = right_node->prev;
        right_node->prev = newNode;
        newNode->next = right_node;
        newNode->prev = tem;
        tem->next = newNode;
        len += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index > len) {return;}
        ListNode* cur = left_node->next;
        ListNode* newNode = new ListNode(val);
        while(index > 0)
        {
            cur = cur->next;
            index -= 1;
        }
        newNode->prev = cur->prev;
        cur->prev = newNode;
        newNode->prev->next = newNode;
        newNode->next = cur; 
        len += 1;
    }
    
    void deleteAtIndex(int index) {
        if(index >= len) {return;}
        ListNode* cur = left_node->next;
        while(index > 0)
        {
            cur = cur->next;
            index--;
        }

        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        cur->prev = nullptr;
        cur->next = nullptr;
        len -= 1;
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