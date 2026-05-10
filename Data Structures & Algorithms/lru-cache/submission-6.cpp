class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr), key(0), value(0) {}
    Node(int key, int value) : next(nullptr), prev(nullptr), key(key), value(value) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void add(int key, int value) {
        Node* temp = new Node(key, value);
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next->prev = temp;
    }

    void remove() {
        // remove tails previous
        Node* toDelete = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        delete toDelete;
    }

    Node* lru() {
        return tail->prev;
    }

    Node* getRecent() {
        return head->next;
    }

    void fixOrder(Node* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->prev = head;
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> cache;
    LinkedList ll;
    LRUCache(int capacity): ll() {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            Node* temp = cache[key];
            ll.fixOrder(temp);
            return temp->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* temp = cache[key];
            temp->value = value;
            ll.fixOrder(temp);
            return;
        }

        if(capacity <= 0) {
            Node* lru = ll.lru();
            cache.erase(lru->key);
            ll.remove();
            capacity++;
        }

        ll.add(key, value);
        cache[key] = ll.getRecent();
        capacity--;
    }
};