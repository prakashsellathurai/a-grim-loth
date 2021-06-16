#include <iostream>
#include <ostream>
typedef struct list {
  int item;
  list *next;
} list;

void inserList(list **l, int x) {
  list *p = new list;
  p->item = x;
  p->next = *l;
  *l = p;
}
list *searchList(list *l, int x) {
  if (l == NULL)
    return NULL;
  if (l->item == x) {
    return l;
  } else {
    return searchList(l->next, x);
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
  while (l) {
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
int main() {
  list *root; // This will be the unchanging first list

  root = new list; // Now root points to a node struct
  root->next = 0;  // The node root points to has its next pointer
                   //  set equal to a null pointer
  root->item = 5;  // By using the -> operator, you can modify the node
  //  a pointer (root in this case) points to.

  inserList(&root, 1);
  inserList(&root, 2);
  inserList(&root, 3);
  inserList(&root, 14);
  std::cout << "After insert option : ";
  PrintList(root);
  std::cout << "searching the list : " << searchList(root, 5)->item << std::endl;
  deleteItem(&root, 5);
  std::cout << "after deletion : ";
  PrintList(root);
}