class ListNode:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.left_node = ListNode(0)
        self.right_node = ListNode(0)
        self.length = 0
        self.left_node.next = self.right_node
        self.right_node.prev = self.left_node

    def get(self, index: int) -> int:
        if index >= self.length:
            return -1
        else:
            cur = self.left_node.next
            while(index > 0):
                cur = cur.next
                index -= 1
            return cur.val

    def addAtHead(self, val: int) -> None:
        new_node = ListNode(val)
        new_node.prev = self.left_node
        new_node.next = self.left_node.next
        self.left_node.next.prev = new_node
        self.left_node.next = new_node
        self.length += 1

    def addAtTail(self, val: int) -> None:
        new_node = ListNode(val)
        new_node.prev = self.right_node.prev
        new_node.next = self.right_node
        self.right_node.prev.next = new_node
        self.right_node.prev = new_node
        self.length += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if(index > self.length): 
            return 
        else:
            cur = self.left_node.next
            new_node = ListNode(val)
            while(index > 0):
                cur = cur.next
                index -= 1
            new_node.prev = cur.prev
            new_node.next = cur
            cur.prev = new_node
            new_node.prev.next = new_node
            self.length += 1

    def deleteAtIndex(self, index: int) -> None:
        if(index >= self.length): 
            return 
        else:
            cur = self.left_node
            while(index > 0):
                cur = cur.next
                index -= 1
            cur.prev.next = cur.next
            cur.next.prev = cur.prev
            cur.next = None
            cur.prev = None
            self.length -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)