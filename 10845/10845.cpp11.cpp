#include <iostream>
#include <string>

using namespace std;

template <class Element>
class CircularQueue {
private:
	int front;
	int rear;

	enum SIZE {
		MAX_QUEUE_SIZE = 10000
	};

	Element arr[MAX_QUEUE_SIZE];

public:

	CircularQueue() {
		front = 0;
		rear = 0;
	}

	virtual ~CircularQueue() {

	}
	void enqueue(const Element &e) {
		if (is_full()) {
			cout << -1 << endl;
			return;
		}
		rear = increase_circular(rear);
		arr[rear] = e;
	}

	Element dequeue() {
		if (is_empty()) {
			return -1;
		}
		front = increase_circular(front);
		Element e = arr[front];

		return e;
	}

	int increase_circular(int index) {
		return (index + 1) % MAX_QUEUE_SIZE;
	}
	bool is_empty() {
		return front == rear;
	}

	bool is_full() {
		return increase_circular(rear) == front;
	}

	Element get_front() {
		if (is_empty()) {
			return -1;
		}
		else {
			return arr[increase_circular(front)];
		}
	}

	Element get_back() {
		if (is_empty()) {
			return -1;
		}
		else {
			return arr[rear];
		}
	}

	int get_size() {
		return rear - front;
	}
};

int main() {

	int n = 0;
	cin >> n;

	CircularQueue<int> queue;

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int temp;
			cin >> temp;

			queue.enqueue(temp);
		}
		
		else if (command == "pop") {
			cout << queue.dequeue() << endl;
		}
		else if (command == "front") {
			cout << queue.get_front() << endl;
		}
		else if (command == "back") {
			cout << queue.get_back() << endl;
		}
		else if (command == "size") {
			cout << queue.get_size() << endl;
		}
		else if (command == "empty") {
			cout << queue.is_empty() << endl;
		}

	}

	return 0;

}