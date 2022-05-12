#ifndef LINKED_LIST
#define LINKED_LIST
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* next;
	Node() { next = nullptr; }
	Node(T& item, Node* ptr = nullptr) { data = item; next = ptr; }
};

template<class T>
class LinkedList {
public:

	Node<T>* head, *tail;

	LinkedList() { make_empty(); }
	void make_empty() {
		Node<T>* dummy_head = new Node<T>();
		tail = head = dummy_head;
	}

	bool is_empty() {
		return head == tail;
	}

	void insert_to_end(T& item){
		Node<T>* node = new Node<T>(item);
		if (is_empty())
			head->next = node;
		tail->next = node;
		tail = node;
	}

	void delete_after(Node<T>* node) {
		Node<T>* temp = node->next;
		node->next = node->next->next;
		if (temp == tail)
			tail = node;

		delete temp;
	}

	~LinkedList() {
		Node<T>* next, *curr = head;
		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
};

#endif
