
#include <algorithm>
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
    return -1;
  }

  int x = height(r->right);
  int y = height(r->left);

  return 1 + max(x, y);
}

Node *ISbalanced(Node *r) {
  if (r == nullptr) {
    return nullptr;
  }

  if (bf(r) > 1 || bf(r) < -1) {
    return r;
  }

  Node *x = ISbalanced(r->right);
  Node *y = ISbalanced(r->left);

  if (x != nullptr) {
    return x;
  }

  if (y != nullptr) {
    return y;
  }

  return nullptr;
}

int main() {
  Node *root = nullptr;

  int arr[] = {1, 3, 2};

  for (int i = 0; i < 3; i++) {
    root = insertion(root, *(arr + i));
  }

  cout << "Height: " << height(root) << endl;
  cout << "Balance Factor: " << balanceFactor(root) << endl;

  return 0;
}
