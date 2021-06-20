// Write a program to reverse the direction of a given singly-linked list. In
// other words, after the reversal all pointers should now point backwards. Your
// algorithm should take linear time.

#include <iostream>
#include <ostream>
#include <stack>
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

void reverseLinkedlist(list **root) {
  std::stack<list *> stackBucket;
  list *ptr = *root;
  stackBucket.push(ptr);
  while (ptr->next != NULL) {
    stackBucket.push(ptr->next);
    ptr = ptr->next;
  }
  *root = ptr;
  while (!stackBucket.empty()) {
    ptr->next = stackBucket.top();
    stackBucket.pop();
    ptr = ptr->next;
  }
  ptr->next = NULL;
}
void reverseIterativeLinkedlist(list **root) {

 
   list *prev = NULL;
   list *curr = *root;
   list *next_ = NULL;

  while (curr != NULL) {
    next_ = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next_;
  }
  *root = prev;
}
int main() {
  list *root =
      NULL; // This will be the unchanging first listal to a null pointer

  inserList(&root, 10);
  inserList(&root, 2);
  inserList(&root, 0);
  inserList(&root, 5);
  inserList(&root, 14);
  PrintList(root);
  reverseLinkedlist(&root);
  std::cout << "After reversal" << std::endl;
  PrintList(root);
  reverseIterativeLinkedlist(&root);

  std::cout << "Again After reversal" << std::endl;
  PrintList(root);
}