#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkList {
public:
    int lenght;
    Node* head;
    Node* curr;
    int odd_count=0;

    LinkList() {
        lenght = 0;
        head = nullptr;
        curr = nullptr;
    }

    void createList(int value) {
        if (head == nullptr) {
            head = new Node(value);
        }
        else {
            Node* temp;
            temp = new Node(value);
            temp->next = head;
            head = temp;
        }

        lenght++;
    }

    void display() {
        start();
        cout << "Linked List: ";

        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void start() {
        curr = head;
    }

    void tail() {
        start();

        for (int i = 0; i < lenght - 1; i++) {
            curr = curr->next;
        }
    }

    void insertion(int value, int position) {
        if (position < 1 || position > lenght + 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1) {
            Node* temp;
            temp = new Node(value);
            temp->next = head;
            head = temp;
            lenght++;
        }

        else if (position == lenght + 1) {
            Node* temp;
            temp = new Node(value);
            tail();
            curr->next = temp;
            lenght++;
        }

        else {
            start();

            Node* temp;
            temp = new Node(value);

            for (int i = 0; i < position - 2; i++) {
                curr = curr->next;
            }

            temp->next = curr->next;
            curr->next = temp;
            lenght++;
        }
    }
    






    //Task 2

    int getSum(Node* temp) {
        if (temp == nullptr) {
            return 0;
        }

        return temp->data + getSum(temp->next);
    }

    double getAverage() {
        return (double)getSum(head) / lenght;
    }








    //Task 3
    int countOdd(Node* temp) {
        if (temp == nullptr) {
            return 0;
        }

        if (temp->data % 2 != 0) {
            return 1 + countOdd(temp->next);
        }

        return countOdd(temp->next);
    }






    
};

int main() {
    LinkList l1;

    l1.createList(3);
    l1.createList(12);
    l1.createList(8);
    l1.createList(4);
    l1.createList(34);

    l1.insertion(100, 1);
    l1.insertion(200, 3);

    l1.display();

    cout << "Average: " << l1.getAverage() << endl;
    cout << "Odd Numbers: " << l1.countOdd(l1.head) << endl;

    return 0;
}