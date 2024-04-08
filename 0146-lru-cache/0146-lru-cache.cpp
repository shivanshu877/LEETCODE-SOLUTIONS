class LRUCache {
public:
    class Node {
        public:
        int key;
        int val ;
        Node * next ;
        Node* prev ;
        Node(int key_ , int val_){
            key = key_ ;
            val = val_ ;
        }
    };
    void addNode(Node * newNode) {
    auto x = head->next ;
   
    newNode->next = x;
    newNode->prev = head;
    head->next = newNode;
    x->prev = newNode;
    }
    void deleteNode(Node *delNode) {
    auto p = delNode->prev;
    auto n = delNode->next ;
    p->next = n ;
    n->prev = p ;
    }
    
    
    int cap ;
    unordered_map<int , Node*> m ;
    Node * head =new Node(-1 , -1) ;
    Node * tail = new Node(-1 , -1) ;

    LRUCache(int capacity) {
        
        cap = capacity ;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key_) {
        if(m.find(key_)!= m.end()){
         auto temp = m[key_] ;
         int res = temp->val ;
         m.erase(key_);
         deleteNode(temp);
         addNode(temp);
         m[key_] =  head->next ;
            return res;
         
        }
        return -1;
    }
    
    void put(int key_, int value) {
         if (m.find(key_) != m.end()) {
      Node * existingnode = m[key_];
      m.erase(key_);
      deleteNode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deleteNode(tail -> prev);
    }

    addNode(new Node(key_, value));
    m[key_] = head -> next;
    }
};

