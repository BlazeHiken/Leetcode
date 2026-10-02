class LRUCache {
public:

    // LL will be leaset recently used to recently used
    // so move new inputs and old gets to the end
    // remove node 1 to add more nodes if max cap reached
    struct Node {
        int key;
        int value;
        Node *next = NULL;
        Node *prev = NULL;

        Node(int key, int val) {
            this->key = key;
            this->value = val;
        }
    };

    unordered_map<int, Node*> mp;
    int cap;
    Node dummy{-1,0};
    Node *tail = &dummy;

    void moveToTail(Node *recent) {
        if(recent==tail) return;
        recent->prev->next = recent->next;
        recent->next->prev = recent->prev;
        recent->prev = tail;
        tail->next = recent;
        tail = recent;
    }

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            moveToTail(mp[key]);
            return mp[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(!mp.count(key)) {  // key not found
            Node *newNode = new Node(key,value);
            
            if(mp.size()<cap) {  // no key and has space
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;

            } else { // no key no space
                Node *victim = dummy.next; //replace node 1 by newnode
                victim->prev->next = newNode;
                if(victim!=tail) {
                    victim->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                newNode->prev = victim->prev;
                newNode->next = victim->next;
                mp.erase(victim->key);
                delete victim;
                moveToTail(newNode); // make newnode recent
            }
            mp[key] = newNode;

        } else {  // key found
            mp[key]->value = value;
            moveToTail(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */