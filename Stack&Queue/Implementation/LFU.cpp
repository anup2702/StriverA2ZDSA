class LFUCache {
public:
    class Node {
    public:
        int key, val, cnt;
        Node *prev, *next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->cnt = 1;
            prev = next = nullptr;
        }
    };

    class List {
    public:
        int size;
        Node *head, *tail;
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void deln(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        void ins(Node* node) {
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            size++;
        }
    };

    int capacity, minfreq, cursize;
    map<int, Node*> cache;   // key -> Node
    map<int, List*> freq;    // freq -> List of nodes

    LFUCache(int capacity) {
        this->capacity = capacity;
        cursize = 0;
        minfreq = 0;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            update(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            update(node);
        } else {
            if (cursize >= capacity) {
                // Remove least frequently used node
                Node* node = freq[minfreq]->tail->prev;
                cache.erase(node->key);
                freq[minfreq]->deln(node);
                cursize--;
            }
            Node* newn = new Node(key, value);
            minfreq = 1;
            List* list = new List();
            if (freq.find(minfreq) != freq.end())
                list = freq[minfreq];
            list->ins(newn);
            freq[minfreq] = list;
            cache[key] = newn;
            cursize++;
        }
    }

    void update(Node* node) {
        freq[node->cnt]->deln(node);
        if (node->cnt == minfreq && freq[node->cnt]->size == 0)
            minfreq++;
        List* list = new List();
        if (freq.find(node->cnt + 1) != freq.end())
            list = freq[node->cnt + 1];
        node->cnt++;
        list->ins(node);
        freq[node->cnt] = list;
    }
};
