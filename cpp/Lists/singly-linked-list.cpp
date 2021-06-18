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
int main() {
  list *root = NULL;

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