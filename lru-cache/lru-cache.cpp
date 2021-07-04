struct Node{
    int val;
    int key;
    Node *prev, *next;
    Node(){
        prev = NULL;
        next = NULL;
    }
    Node(int k, int v){
        prev = NULL;
        next = NULL;
        this->key = k;
        this->val = v;
    }
};

class LRUCache {
    int capacity;
    int size;
    Node* head, *tail;
    map<int, Node*> m;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if (!m[key]){
            return -1;
        }
        else{
            //first update list
            Node *temp = m[key];
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;
            return temp->val;
        }  
    }
    
    void put(int key, int value) {
        if(m[key]){
            Node * temp = m[key];
            temp->val = value;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;
            return;
        }
        else{
            Node *newnode = new Node(key, value);
            newnode->next = head->next;
            newnode->prev = head;
            head->next->prev = newnode;
            head->next = newnode;
            m[key] = newnode;
            
            if(size < capacity){
                size++;
                return;
            }
            else{
                Node *del = tail->prev;
                tail->prev = del->prev;
                del->prev->next = del->next;
                del->next = NULL;
                del->prev = NULL;
                m.erase(del->key);
                return;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */