#include <iostream>
using namespace std;

typedef struct Node {
  int data;
  Node *next;
} Node;

void insert(Node **head, int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->next = NULL;

  if (head == NULL) {
    *head = temp;
  } else {
    Node *lastnode = *head;

    while (lastnode->next != NULL) {
      lastnode = lastnode->next;
    }
    lastnode->next = temp;
  }
  return;
}

void printList(Node *head) {
  struct Node *ptr = head;
  std::cout << std::endl;
  while (ptr != NULL) {
    if (ptr->data)
      std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

Node *merge_sorted_list(Node *a, Node *b) {
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;

  Node *result = new Node();

  if (a->data < b->data) {
    result = a;
    result->next = merge_sorted_list(a->next, b);
  } else {
    result = b;
    result->next = merge_sorted_list(a, b->next);
  }
  return result;
}
int main() {
  int keys[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(keys) / sizeof(keys[0]);

  Node *list1 = new Node();
  Node *list2 = new Node();
  int i;
  for (i = 0; i < n / 2; i++) {
    insert(&list1, keys[i]);
  }
  for (; i < n; i++) {
    insert(&list2, keys[i]);
  }

  Node *merged_list = merge_sorted_list(list1, list2);
  printList(merged_list);
  return 0;
}
