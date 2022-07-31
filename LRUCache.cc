#include<unordered_map>
using namespace std;

/*
    note: LRUCache 最近最少使用
    1. 因为插入和查找需要以O(1)的时间复杂度运行，插入需要O(1)则选择双向链表，查找需要O(1)则用哈希表
    2. 为了处理特殊的头尾节点，直接在内部定义指针方便插入和删除
    3. 还需要一个记录实时大小的size
*/

struct Node {
    int key;
    int value;
    Node *left, *right;
    Node(int k=0, int v=0) : key(k), value(v), left(NULL), right(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity), _size(0) {
        _head = new Node();
        _tail = new Node();
        _head->right = _tail;
        _tail->left = _head;
    }
    
    int get(int key) {
        if (_map.count(key) == 0) {
            return -1;
        }

        Node *p = _map[key];
        move_to_head(p);
        return p->value;
    }
    
    void put(int key, int value) {
        if (_map.count(key) != 0) {
            Node *p = _map[key];
            p->value = value;
            move_to_head(p);

        } else {
            Node *p = new Node(key, value);
            add_node(p);
            _map[key] = p;
            _size++;
            if (_size > _capacity) {
                Node *tail = _tail->left;
                remove_node(tail);
                _map.erase(tail->key);
                delete tail;
                _size--;
            }
        }
    }

private:
    int _capacity;
    int _size;
    Node *_head, *_tail;
    unordered_map<int, Node*> _map;

    void add_node(Node *p) {
        p->left = _head;
        p->right = _head->right;
        _head->right->left = p;
        _head->right = p;
    }

    void remove_node(Node *p) {
        p->right->left = p->left;
        p->left->right = p->right;
    }

    void move_to_head(Node *p) {
        remove_node(p);
        add_node(p);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */