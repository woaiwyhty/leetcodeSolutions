
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct Node {
	Node *prev, *next;
	int value;
	Node() : prev(NULL), next(NULL) {}
};
class LRUCache {
public:
	LRUCache() {

	}
	LRUCache(int capacity) {
		head = NULL, tail = NULL;
		cnt = 0; limit = capacity;
	}

	int get(int key) {
		if (vals.find(key) == vals.end()) return -1;
		Node *tmp = frequency[key];
		removeNode(tmp);
		insertToTail(tmp);
		return vals[key];
	}

	void put(int key, int value) {
		if (vals.find(key) == vals.end()) {
			if (cnt == limit) {
				Node *oldHead = head;
				removeNode(oldHead);
				vals.erase(oldHead->value);
				frequency.erase(oldHead->value);
				delete oldHead;
				oldHead = NULL;
				cnt--;
			}
			Node *node = new Node();
			node->value = key;
			vals[key] = value;
			frequency[key] = node;
			insertToTail(node);
			++cnt;
		}
		else {
			Node *node = frequency[key];
			vals[key] = value;
			removeNode(node);
			insertToTail(node);
		}
	}
private:
	map<int, Node*> frequency;
	map<int, int> vals;
	Node *head, *tail;
	int cnt, limit;
	void removeNode(Node *node) {
		if (node != head && node != tail) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		else if (node == head) {
			if (!node->next) head = NULL, tail = NULL;
			else {
				node->next->prev = NULL;
				head = node->next;
			}
		}
		else {
			node->prev->next = NULL;
			tail = node->prev;
		}
		node->prev = NULL, node->next = NULL;
	}
	void insertToTail(Node *node) {
		if (!head) {
			head = node, tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}
}sol;

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/

int main()
{
	LRUCache *obj = new LRUCache(1);
	cout << obj->get(5) << endl;
	cout << obj->get(5) << endl;
	obj->put(1, 5);
	obj->put(2, 4);
	obj->put(-5, 2);
	cout << obj->get(-5) << endl;
	obj->put(-6, 2);
	cout << obj->get(1) << endl;
    return 0;
}

