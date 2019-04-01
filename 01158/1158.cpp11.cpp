#include <iostream>
#include <memory>

using namespace std;

template <class Element>
class Node {
private:
	Element data;
	Node *next;
	Node *prev;
public:
	Node() {}

	Node(Element data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}

	virtual ~Node(){
		next = NULL;
		prev = NULL;
	}

	void SetNext(Node *next) {
		this->next = next;
	}
	
	void SetPrev (Node *prev) {
		this->prev = prev;
	}

	Node *GetNext() {
		return next;
	}
	
	Node *GetPrev() {
		return prev;
	}
	
	Element GetData() {
		return data;
	}

};

template <class Element>
class MyList {
private:
	Node<Element> *head;
	Node<Element> *tail;

	int size;

	void RemoveNode(Node<Element> *rm) {
		
		if (size == 0) {
			return;
		}
		else if (size == 1) {
			head == NULL;
			tail == NULL;
			
			delete rm;
			size--;
			return;
		}

		Node<Element> *prevNode = rm->GetPrev();
		Node<Element> *nextNode = rm->GetNext();

		if (rm == tail) {
			tail = prevNode;
		}
		else if (rm == head) {
			head = nextNode;
		}

		prevNode->SetNext(nextNode);
		nextNode->SetPrev(prevNode);

		delete rm;

		size--;
	}

public:
	MyList() {
		head = NULL;
		tail = NULL;

		size = 0;
	}

	virtual ~MyList() {
	}

	void Insert(Element data) {
		Node<Element> *node = new Node<Element>(data);

		if (size == 0) {
			head = node;
			tail = node;
		}
		node->SetNext(head);
		node->SetPrev(tail);

		tail->SetNext(node);

		tail = node;
		size++;
	}


	void Erase(Element data) {
		Node<Element> *temp = head;

		int loop = 0;

		while (loop <= size) {
			if (temp->GetData() == data) {
				Node <Element> *rm = temp;
				temp = temp->GetNext();
				RemoveNode(rm);
			}
			else {
				temp = temp->GetNext();
			}
			loop++;
		}
	}

	Element EraseAt(int idx) {

		Node<Element> *temp = head;
		
		for (int i = 0; i < idx; i++){
			temp = temp->GetNext();
		}

		Element ret = temp->GetData();
		RemoveNode(temp);
		return ret;
	}
	void PrintAll() {
		Node<Element> *node = head;

		while (node != tail) {
			std::cout << node->GetData() << "->";
			node = node->GetNext();
		}
		std::cout << node->GetData() << "-> head" << std::endl;
	}

	void PrintReverse() {
		Node<Element> *node = tail;

		while (node != head) {
			std::cout << node->GetData() << "->";
			node = node->GetPrev();
		}
		std::cout << node->GetData() << "-> tail" << std::endl;

	}

	int Size() {
		return size;
	}
	bool IsEmpty() {
		return size == 0;
	}

	void Josephus(int m) {
		Node<Element> *temp = head;
		cout << "<";
		while (!IsEmpty()) {
			for (int i = 1; i < m; i++) {
				temp = temp->GetNext();
			}
			int data = temp->GetData();
			RemoveNode(temp);

			if (size>1) {
				cout << data << ", ";
			}
			else {
				cout << data << ">";
			}
		}
	}

};

int main() {

	MyList<int> josephus;

	int n = 0;
	int m = 0;

	std::cin >> n;
	std::cin >> m;

	for (int i =1; i <= n; i++) {
		josephus.Insert(i);
	}

	int idx = m - 1;

	cout << "<";
	while (true) {
		int t = josephus.EraseAt(idx);

		cout << t;
		if (josephus.IsEmpty()) {
			break;
		}
		cout << ", ";
		idx = (idx + m - 1) % josephus.Size();
	}

	cout << ">";

	return 0;

}