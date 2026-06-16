typedef struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
} Node;

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(0, 0);
        tail=new Node(0, 0);
        head->next= tail;
        tail->prev= head;
    }

    void deleteNode(Node* node) {
        Node* prevNode=node->prev;
        Node* afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
    }

    void insertToFront(Node* node)
     { //insert after head 
        Node* headAfter=head->next;
        head->next=node;
        node->prev=head;
        node->next=headAfter;
        headAfter->prev=node;
    }

    int get(int key) 
    {
        if(mp.find(key)==mp.end()) return -1;

        Node* node=mp[key];
        deleteNode(node);
        insertToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if(mp.find(key)!= mp.end()) 
        { 
            Node* node= mp[key];
            node->val= value;
            deleteNode(node);
            insertToFront(node);
        }
        else 
        { 
            if(mp.size()== cap) 
            { 
                Node* lru= tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru; 
            }
            Node* node=new Node(key, value); 
            mp[key]=node;
            insertToFront(node);
        }
    }
};