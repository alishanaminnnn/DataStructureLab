#include <iostream>
#include <string>
using namespace std;

// A fixed-capacity list that stores strings.
class ArrayList {
private:
    string* arr;    // Dynamic array for storing words
    int size;       // Number of currently stored elements
    int capacity;   // Maximum number of elements

    // Returns true when no more elements can be added.
    bool isFull() {
        return size == capacity;
    }

    // Checks whether an index refers to an existing element.
    bool isValidIndex(int index) {
        return index >= 0 && index < size;
    }

public:
    // Creates a list with the given capacity.
    ArrayList(int capacity) {
        // Use a default capacity if an invalid value is provided.
        if (capacity <= 0) {
            capacity = 10;
        }

        this->capacity = capacity;
        size = 0;
        arr = new string[capacity];
    }

    // Frees dynamically allocated memory.
    ~ArrayList() {
        delete[] arr;
    }

    // Adds a word to the end of the list.
    void add(string word) {
        if (isFull()) {
            cout << "List is full.\n";
            return;
        }

        arr[size] = word;
        size++;
    }

    // Removes the element at a specified index.
    void remove(int index) {
        if (!isValidIndex(index)) {
            cout << "Invalid index.\n";
            return;
        }

        // Shift all following elements one position left.
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Removes every occurrence of a given word.
    void removeByValue(string word) {
        for (int i = 0; i < size;) {
            if (arr[i] == word) {
                remove(i);
                cout << word << " has been removed!\n";
                // Do not increment i because elements shifted left.
            } else {
                i++;
            }
        }
    }

    // Searches for a word and returns true if it exists.
    bool search(string word) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == word) {
                cout << word << " has been found! ";
                return true;
            }
        }

        cout << word << " has not been found! ";
        return false;
    }

    // Returns the index of the first matching word, or -1 if absent.
    int retrieve(string word) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == word) {
                cout << word << " index is ";
                return i;
            }
        }

        cout << "Value not found! ";
        return -1;
    }

    // Replaces every matching old word with a new word.
    void replace(string oldWord, string newWord) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == oldWord) {
                arr[i] = newWord;
                cout << oldWord << " replaced by " << newWord << '\n';
            }
        }
    }

    // Removes all elements logically by resetting the size.
    void clear() {
        size = 0;
        cout << "All elements have been removed!\n";
    }
};

int main() {
    // Create a list that can contain up to six strings.
    ArrayList list(6);

    // Add items to the list.
    list.add("apple");
    list.add("aliyan");
    list.add("books");

    // Test list operations.
    list.removeByValue("books");
    cout << list.search("aliyan") << endl;
    cout << list.retrieve("aliyan") << endl;
    list.replace("apple", "mango");
    list.clear();

    return 0;
}