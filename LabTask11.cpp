
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  int height;

  Node(int value) : data(value), left(nullptr), right(nullptr), height(0) {}
};

Node *insertion(Node *r, int data) {
  if (r == nullptr) {
    return new Node(data);
  }

  if (data >= r->data) {
    r->right = insertion(r->right, data);
  } else {
    r->left = insertion(r->left, data);
  }

  return r;
}


int height(Node *r) {
  if (r == nullptr) {
    return 0;
  }
  int x = height(r->right);
  int y = height(r->left);
  return y-x;
}

int main() {
  Node *root = nullptr;

  int arr[] = {1, 2, 4, 8, 5, 3, 9, 0};

  for (int i = 0; i < 8; i++) {
    root = insertion(root, *(arr + i));
  }

  return 0;
}
