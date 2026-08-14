
class SiteNode{
    public:
        SiteNode* prev;
        SiteNode* next;
        string url;
    SiteNode():url{}, prev{nullptr}, next{nullptr} {}
    SiteNode(string x): url{x}, prev{nullptr}, next{nullptr} {}
};

class BrowserHistory {
public:
    SiteNode* leftNode;
    SiteNode* rightNode;
    SiteNode* cur;
    int len;
    BrowserHistory(string homepage) {
        leftNode = new SiteNode();
        rightNode = new SiteNode();
        cur = new SiteNode(homepage);
        leftNode->next = cur;
        rightNode->prev = cur;
        leftNode->prev = nullptr;
        rightNode->next = nullptr;
        cur->next = rightNode; 
        cur->prev = leftNode;
        len = 1;
    }
    
    void visit(string url) {
        SiteNode* newNode = new SiteNode(url);
        cur->next = newNode;
        newNode->prev = cur;
        rightNode->prev = newNode;
        newNode->next = rightNode;
        cur = newNode;
        len += 1;
    }
    
    string back(int steps) {
        while(steps > 0 && cur->prev != leftNode)
        {
            cur = cur->prev;
            steps --;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while(steps > 0 && cur->next != rightNode)
        {
            cur = cur->next;
            steps --;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */