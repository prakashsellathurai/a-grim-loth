#include <iostream>
using namespace std;

// A Linked List Node
struct Node {
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

void printList(Node *node) {
  while (node != nullptr) {
    cout << node->data << " —> ";
    node = node->next;
  }
  cout << "nullptr";
}

Node *sortedMerge(Node *a, Node *b) {
  // base cases
  if (a == nullptr) {
    return b;
  }

  else if (b == nullptr) {
    return a;
  }

  Node *result;

  if (a->data <= b->data) {
    result = a;
    result->next = sortedMerge(a->next, b);
  } else {
    result = b;
    result->next = sortedMerge(a, b->next);
  }

  return result;
}
Node *merge_K_sortedList(Node *list[], int k) {

  int last = k - 1;
  while (last != 0) {
    int i = 0, j = last;

    while (i < j) {
      list[i] = sortedMerge(list[i], list[j]);
      i++, j--;
      if (i >= j) {
        last = j;
      }
    }
  }
  return list[0];
}

int main(int argc, const char **argv) {
  int k = 3; // total number of linked lists

  // an array to store the head nodes of the linked lists
  Node *list[k];

  list[0] = new Node(1);
  list[0]->next = new Node(5);
  list[0]->next->next = new Node(7);

  list[1] = new Node(2);
  list[1]->next = new Node(3);
  list[1]->next->next = new Node(6);
  list[1]->next->next->next = new Node(9);

  list[2] = new Node(4);
  list[2]->next = new Node(8);
  list[2]->next->next = new Node(10);

  Node *mergedKsortedList = merge_K_sortedList(list, k);
  printList(mergedKsortedList);
  return 0;
}
