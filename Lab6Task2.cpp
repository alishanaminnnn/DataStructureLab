#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = nullptr;
        }
    };

    Node* top;
    int size = 0;

    bool isEmpty()
    {
        return size == 0;
    }

public:
    // Default constructor
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    // Parameterized constructor
    Stack(int val)
    {
        top = new Node(val);
        size = 1;
    }

    // Copy constructor: creates independent nodes
    Stack(const Stack& s)
    {
        top = nullptr;
        size = 0;

        Node* curr = s.top;
        Stack temp;

        while (curr != nullptr)
        {
            temp.push(curr->data);
            curr = curr->next;
        }

        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }

    // Push an element
    void push(int val)
    {
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
        size++;
    }

    // Pop the top element
    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }

        Node* temp = top;
        int data = temp->data;

        top = top->next;
        delete temp;
        size--;

        return data;
    }

    // Return the top element
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }

        return top->data;
    }

    // Return stack size
    int getSize()
    {
        return size;
    }

    // Destructor
    ~Stack()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Check whether the stack is a palindrome
bool palindrome(Stack s1)
{
    int length = s1.getSize();
    int* arr = new int[length];

    // Store stack elements in an array
    for (int i = 0; i < length; i++)
    {
        arr[i] = s1.pop();
    }

    // Compare the array with its reverse
    for (int i = 0; i < length / 2; i++)
    {
        if (arr[i] != arr[length - 1 - i])
        {
            delete[] arr;
            return false;
        }
    }

    delete[] arr;
    return true;
}

int main()
{
    Stack s1;

    s1.push(2);
    s1.push(4);
    s1.push(5);
    s1.push(5);
    s1.push(4);
    s1.push(2);

    if (palindrome(s1))
    {
        cout << "The Stack is Palindrome..";
    }
    else
    {
        cout << "The Stack is Not Palindrome..";
    }

    return 0;
}