#include <iostream>
using namespace std;

class DoubleCircular
{
private:
    // Node stores one element and links to the next and previous nodes
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node *head; // Points to the first node
    int size;   // Stores the number of elements

    bool isEmpty() { return (head == nullptr); }

    bool isValidIndex(int index)
    {
        return (index >= 0 && index < size);
    }

public:
    DoubleCircular();
    DoubleCircular(int value);
    ~DoubleCircular();

    void add(int value);
    void insert(int index, int value);
    void remove(int index);
    int get(int index);
    void set(int index, int value);
    int getSize();
    void display(bool reverse = false);

    Node *tail()
    {
        if (head == nullptr)
            return nullptr;

        return head->prev;
    }
};

int main()
{
    DoubleCircular list;

    list.add(10);
    list.add(20);
    list.add(30);

    list.display();

    list.insert(1, 15);
    list.display();

    list.remove(2);
    list.display();

    list.set(1, 70);
    list.display();

    list.display(true);

    cout << "Element at index 1: " << list.get(1) << endl;
    cout << "Size: " << list.getSize() << endl;

    return 0;
}

// Default Constructor
DoubleCircular::DoubleCircular()
{
    // Creates an empty list
    head = nullptr;
    size = 0;
}

// Parameterized Constructor
DoubleCircular::DoubleCircular(int value)
{
    // Creates a list containing one element
    head = new Node(value);

    head->next = head;
    head->prev = head;

    size = 1;
}

// Destructor
DoubleCircular::~DoubleCircular()
{
    if (head == nullptr)
        return;

    Node *curr = head->next;

    while (curr != head)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }

    delete head;

    head = nullptr;
    size = 0;
}

// Add element at the end
void DoubleCircular::add(int value)
{
    Node *newNode = new Node(value);

    // If the list is empty
    if (isEmpty())
    {
        head = newNode;

        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *temp = tail();

        newNode->prev = temp;
        newNode->next = head;

        temp->next = newNode;
        head->prev = newNode;
    }

    size++;
}

// Insert element at a specific index
void DoubleCircular::insert(int index, int value)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid index." << endl;
        return;
    }

    // If inserting into an empty list
    if (size == 0)
    {
        if (index == 0)
        {
            add(value);
        }
        return;
    }

    Node *newNode = new Node(value);

    Node *temp = tail();

    // Insert at the beginning
    if (index == 0)
    {
        newNode->next = head;
        newNode->prev = temp;

        temp->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // Insert at the end
    else if (index == size)
    {
        newNode->prev = temp;
        newNode->next = head;

        temp->next = newNode;
        head->prev = newNode;
    }

    // Insert in the middle
    else
    {
        Node *curr = head;

        // Move to the node immediately before the insertion position
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;
    }

    size++;
}

// Remove element at a specific index
void DoubleCircular::remove(int index)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }

    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return;
    }

    Node *removalNode = head;

    // Only one node in the list
    if (size == 1)
    {
        delete head;

        head = nullptr;
        size = 0;

        return;
    }

    // Remove first node
    if (index == 0)
    {
        removalNode = head;

        Node *temp = tail();

        head = head->next;

        temp->next = head;
        head->prev = temp;

        delete removalNode;
    }

    // Remove last node
    else if (index == size - 1)
    {
        removalNode = tail();

        Node *temp = removalNode->prev;

        temp->next = head;
        head->prev = temp;

        delete removalNode;
    }

    // Remove from the middle
    else
    {
        Node *curr = head;

        // Move to the node immediately before the removal position
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        removalNode = curr->next;

        curr->next = removalNode->next;
        removalNode->next->prev = curr;

        delete removalNode;
    }

    size--;
}

// Get element at an index
int DoubleCircular::get(int index)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return -1;
    }

    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return -1;
    }

    Node *curr = head;

    // Traverse to the node at the requested index
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }

    return curr->data;
}

// Modify element at an index
void DoubleCircular::set(int index, int value)
{
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }

    if (!isValidIndex(index))
    {
        cout << "Invalid index." << endl;
        return;
    }

    Node *curr = head;

    // Traverse to the node at the requested index
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }

    curr->data = value;
}

// Return current number of elements
int DoubleCircular::getSize()
{
    return size;
}

// Display the list
void DoubleCircular::display(bool reverse)
{
    if (isEmpty())
    {
        cout << "[]" << endl;
        return;
    }

    cout << "[";

    if (!reverse)
    {
        // Display from head to tail
        Node *curr = head;

        for (int i = 0; i < size; i++)
        {
            cout << curr->data;

            if (i < size - 1)
            {
                cout << ", ";
            }

            curr = curr->next;
        }
    }
    else
    {
        // Display from tail to head
        Node *curr = tail();

        for (int i = 0; i < size; i++)
        {
            cout << curr->data;

            if (i < size - 1)
            {
                cout << ", ";
            }

            curr = curr->prev;
        }
    }

    cout << "]" << endl;
}
