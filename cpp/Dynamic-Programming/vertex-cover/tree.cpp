/* Dynamic programming based solution for Vertex Cover problem for a Binary Tree */
#include <iostream>
#include <cstdlib>

int min(int x, int y) { return (x < y) ? x : y; }

/* A binary tree node has data, pointer to left child and a pointer to 
right child */
struct node
{
    int data;
    int vc;
    struct node *left, *right;
    node(int data) : data(data),vc(-1),left(NULL),right(NULL){}
};
// A dynamic programmic based solution that returns size of the minimum vertex cover.
int vertexCover(struct node *root)
{
    // The size of minimum vertex cover is zero if tree is empty or there is only one node i.e. root.
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    // If vertex cover for this node is already evaluated, then return it.
    // to save recomputation of same subproblem again.
    if (root->vc != -1)
        return root->vc;

    // Calculate size of vertex cover when root is part of it
    int size_root_inc = 1 + vertexCover(root->left) + vertexCover(root->right);

    // Calculate size of vertex cover when root is not part of it
    int size_root_exc = 0;
    if (root->left)
        size_root_exc += 1 + vertexCover(root->left->left) + vertexCover(root->left->right);
    if (root->right)
        size_root_exc += 1 + vertexCover(root->right->left) + vertexCover(root->right->right);

    // Minimum of two values is vertex cover, store it before returning.
    root->vc = min(size_root_inc, size_root_exc);

    // returning minimum of the two.
    return root->vc;
}

struct node *newNode(int data)
{
    struct node *temp = new node(data);
    return temp;
};

int main()
{
    struct node *root = newNode(20);
    root->left = newNode(18);
    root->left->left = newNode(40);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(24);
    root->right->right = newNode(25);

    std::cout << "Size of the minimum vertex cover is " << vertexCover(root);
    return 0;
}
