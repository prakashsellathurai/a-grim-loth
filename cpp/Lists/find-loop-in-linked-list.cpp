// Determine whether a linked list contains a loop as quickly as possible
// without using any extra storage. Also, identify the location of the loop.

#include <iostream>
#include <ostream>
typedef struct list {
  int item;
  list *next;
} list;

void inserList(list **l, int x) {
  list *temp = new list();
  temp->item = x;
  temp->next = NULL;

  if (*l == NULL) {
    *l = temp;
  } else {
    list *last_node = *l;
    while (last_node->next != NULL) {
      last_node = last_node->next;
    }
    last_node->next = temp;
  }
  return;
}
list *searchList(list *l, int x) {
  if (l == NULL)
    return NULL;
  else if (l->item == x) {
    return l;
  } else if (l->next != NULL) {
    return searchList(l->next, x);
  } else {
    return NULL;
  }
}
list *PredecessorList(list *l, int x) {
  if (l == NULL || l->next == NULL)
    return NULL;
  if ((l->next)->item == x) {
    return l;
  } else {
    return PredecessorList(l->next, x);
  }
  return NULL;
}
void PrintList(list *l) {
  while (l != NULL) {
    std::cout << l->item << " ";
    l = l->next;
  }
  std::cout << std::endl;
};
void deleteItem(list **l, int x) {
  list *p;
  list *pred;

  p = searchList(*l, x);
  if (p != NULL) {
    pred = PredecessorList(*l, x);
    if (pred == NULL) {
      *l = p->next;
    } else {
      pred->next = p->next;
    }
    free(p);
  }
}

bool detectLoop(list *head) {
  list *slow = head;
  list *fast = head;

  while (slow && fast && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        return true;
    }
  }
  return false;

}
int main() {
  list *root = NULL;

  inserList(&root, 1);
  inserList(&root, 2);
  inserList(&root, 0);
  inserList(&root, 5);
  inserList(&root, 14);
  std::cout << "Loop "<< (detectLoop(root) ? "detected":"not detected")<< std::endl;

   inserList(&root, 20);
  inserList(&root, 4);
  inserList(&root, 15);
  inserList(&root, 10);
root->next->next->next->next = root;
  std::cout << "Loop "<< (detectLoop(root) ? "detected":"not detected")<< std::endl;
}