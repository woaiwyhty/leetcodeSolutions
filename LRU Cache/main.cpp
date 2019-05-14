#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


struct myNode {
    int key, value;
    myNode *next, *prev;
    myNode(int x, int y) : key(x), value(y), next(nullptr), prev(nullptr) { }
};
class LRUCache {
private:
    int n, cur;
    map<int, myNode*> mHash;
    myNode *head, *tail;
public:
    LRUCache(int capacity) {
        n = capacity;
        head = nullptr;
        tail = nullptr;
        cur = 0;
    }

    int get(int key) {
        if (mHash.find(key) == mHash.end()) return -1;
        myNode *now = mHash[key];
        if (now == head) return now->value;
        myNode *next = now->next, *prev = now->prev;
        if (!prev) return now->value;
        now->next = head;
        head->prev = now;
        now->prev = nullptr;
        if (next) {
            prev->next = next;
            next->prev = prev;
        } else {
            prev->next = nullptr;
            tail = prev;
        }
        head = now;
        return now->value;
    }

    void put(int key, int value) {
        if (mHash.find(key) != mHash.end()) {
            myNode *now = mHash[key];
            now->value = value;
            if (now == head) return;
            if (now == tail) {
                tail = now->prev;
                now->prev->next = nullptr;
            }
            myNode *next = now->next, *prev = now->prev;
            if (next) {
                next->prev = prev;
                prev->next = next;
            }
            now->next = head;
            head->prev = now;
            now->prev = nullptr;
            head = now;
            mHash[key] = now;
            return;
        }
        if (cur == n) {
            // need to remove the tail
            myNode *prev = nullptr;

            prev = tail->prev;
            mHash.erase(mHash.find(tail->key));

            delete tail;
            tail = nullptr;
            if (prev) {
                prev->next = nullptr;
                tail = prev;
            } else {
                head = nullptr;
            }
            --cur;
        }
        myNode *now = new myNode(key, value);
        now->next = head;
        if (head) head->prev = now;
        head = now;
        ++cur;
        if (cur == 1) tail = head;

        mHash[key] = now;
    }
};

int main() {
    LRUCache cache = LRUCache( 2 /* capacity */ );

    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);

    cout << cache.get(1)<< endl;
    cout << cache.get(2)<< endl;
    return 0;
}