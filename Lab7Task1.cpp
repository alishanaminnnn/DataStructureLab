#include <iostream>
using namespace std;

class Queue {
private:
  struct Node {
    string data;
    Node *next;
    Node(string value) {
      data = value;
      next = nullptr;
    }
  };
  bool isEmpty() { return size == 0; }
  int size;
  Node *front;
  Node *rear;
  // default constructor
public:
  Queue() {
    size = 0;
    front = nullptr;
    rear = nullptr;
  }
  Queue(string value) {
    front = new Node(value);
    rear = front;
    size = 1;
  }
  void enqueue(string value) {
    Node *temp = new Node(value);
    if (isEmpty()) {
      front = temp;
      rear = temp;
      size = 1;
    } else {
      rear->next = temp;
      rear = temp;
      size++;
    }
  }
  string dequeue() {
    if (isEmpty()) {
      return "";
    }

    string temp = front->data;
    Node *removal = front;

    if (size == 1) {
      front = rear = nullptr;
    } else {
      front = front->next;
    }

    delete removal;
    size--;

    return temp;
  }
  string peek() {
    if (isEmpty()) {
      return "";
    }
    return front->data;
  }
  int getSize() { return size; }
};
int main() {
  Queue q1;
  string players[] = {"Ali", "Ahmed", "Khalid", "Usman", "Farhan"};
  for (int i = 0; i < 5; i++) {
    q1.enqueue(*(players + i));
  }
  int k;
  cout << "Enter K: ";
  cin >> k;

  while (q1.getSize() > 1) {
    for (int i = 1; i < k; i++) {
      q1.enqueue(q1.dequeue());
    }
    cout << q1.dequeue() << " is Eliminated" << endl;
  }
  cout << q1.peek() << " is the winner.....";

  return 0;
}