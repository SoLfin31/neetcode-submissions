
public class LinkNode {
    public int val;
    public LinkNode next;
    public LinkNode prev;
    public LinkNode(int val){
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

public class MyLinkedList {
    private LinkNode left;
    private LinkNode right;
    private int length;

    public MyLinkedList() {
            this.left = new LinkNode(0);
            this.right = new LinkNode(0);
            this.left.next = right;
            this.right.prev = left;
            this.left.prev = null;
            this.right.next = null;
            this.length = 0;
    }
    
    public int Get(int index) {
        if(index >= this.length){ return -1;}
        LinkNode cur = this.left.next;
        while(index > 0)
        {
            cur = cur.next;
            index --;
        }
        return cur.val;
    }
    
    public void AddAtHead(int val) {
        LinkNode newNode = new LinkNode(val);
        newNode.prev = this.left;
        newNode.next = this.left.next;
        this.left.next = newNode;
        newNode.next.prev = newNode;
        this.length ++;
    }
    
    public void AddAtTail(int val) {
        LinkNode newNode = new LinkNode(val);
        newNode.prev = this.right.prev;
        newNode.next = this.right;
        this.right.prev.next = newNode;
        this.right.prev = newNode;
        this.length ++;
    }
    
    public void AddAtIndex(int index, int val) {
        if(index > this.length){return ;}
        LinkNode newNode = new LinkNode(val);
        LinkNode cur = this.left.next;
        while(index > 0)
        {
            cur = cur.next;
            index --;
        }
        newNode.prev = cur.prev;
        newNode.next = cur;
        cur.prev.next = newNode;
        cur.prev = newNode;
        this.length ++;
    }
    
    public void DeleteAtIndex(int index) {
        if(index >= length) {return ;}
        LinkNode cur = this.left.next;
        while(index > 0)
        {
            cur = cur.next;
            index--;
        }
        cur.prev.next = cur.next;
        cur.next.prev = cur.prev;
        cur.next = null;
        cur.prev = null;
        this.length --;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */