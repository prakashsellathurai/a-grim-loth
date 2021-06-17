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
  while (l->next != NULL) {
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
  list *root = new list(); // This will be the unchanging first listal to a null pointer
  root->next = 0; // By using the -> operator, you can modify the node
  // //  a pointer (root in this case) points to.

  inserList(&root, 1);
  inserList(&root, 2);
   inserList(&root, 0);
  inserList(&root, 5);
  inserList(&root, 14);
  std::cout << "After insert option : ";
  PrintList(root);
  std::cout << "searching 3 in the list : " << ((searchList(root, 3) != 0) ? "Found" : "Not Found")<< std::endl;
  deleteItem(&root, 5);
  std::cout << "after deletion : ";
  PrintList(root);
}