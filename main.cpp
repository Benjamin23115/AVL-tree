#include <iostream>
#include <stdexcept>
using namespace std;

// NOTE: i used g++ main.cpp -o main to compile this
template <typename T>
class AVLTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        int height;

        Node(const T &value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node *root;
    int (*compare)(const T &, const T &);
    // Helper function to get the height of a node

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    // Helper function to calculate the balance factor of a node

    int balanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }
    // Helper function to perform a right rotation

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }
    // Helper function to perform a left rotation

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }
    // Helper function to insert a value into the AVL tree

    Node *insert(Node *node, const T &value)
    {
        if (node == nullptr)
            return new Node(value);

        if (compare(value, node->data) == -1)
            node->left = insert(node->left, value);
        else if (compare(value, node->data) == 1)
            node->right = insert(node->right, value);
        else
            throw invalid_argument("Duplicate value not allowed");

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1)
        {
            if (compare(value, node->left->data) == -1) // Left-Left case
                return rotateRight(node);
            if (compare(value, node->left->data) == 1)
            { // Left-Right case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (balance < -1)
        {
            if (compare(value, node->right->data) == 1) // Right-Right case
                return rotateLeft(node);
            if (compare(value, node->right->data) == -1)
            { // Right-Left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }
    // Helper function to find the node with the smallest value in a subtree

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    // Helper function to remove a value from the AVL tree

    Node *remove(Node *node, const T &value)
    {
        if (node == nullptr)
            return node;

        if (compare(value, node->data) == -1)
            node->left = remove(node->left, value);
        else if (compare(value, node->data) == 1)
            node->right = remove(node->right, value);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = (node->left) ? node->left : node->right;
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1)
        {
            if (balanceFactor(node->left) >= 0) // Left-Left case
                return rotateRight(node);
            if (balanceFactor(node->left) < 0)
            { // Left-Right case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (balance < -1)
        {
            if (balanceFactor(node->right) <= 0) // Right-Right case
                return rotateLeft(node);
            if (balanceFactor(node->right) > 0)
            { // Right-Left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }
    // Helper function to search for a value in the AVL tree

    Node *search(Node *node, const T &value)
    {
        if (node == nullptr)
            throw invalid_argument("Value not found");
        if (compare(value, node->data) == -1)
            return search(node->left, value);
        else if (compare(value, node->data) == 1)
            return search(node->right, value);
        else
            return node;
    }
    // Helper function to count the number of elements in the tree

    int count(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + count(node->left) + count(node->right);
    }

public:
    AVLTree(int (*comp)(const T &, const T &)) : root(nullptr), compare(comp) {}

    void insert(const T &value)
    {
        root = insert(root, value);
    }

    T search(const T &value)
    {
        Node *result = search(root, value);
        return result->data;
    }

    void remove(const T &value)
    {
        root = remove(root, value);
    }

    int count()
    {
        return count(root);
    }
};

// Comparison function example
template <typename T>
int compareFunction(const T &a, const T &b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

int main()
{
    AVLTree<int> avlTree(compareFunction<int>);

    // Insert elements
    avlTree.insert(10);
    avlTree.insert(5);
    avlTree.insert(15);
    avlTree.insert(3);
    avlTree.insert(7);
    avlTree.insert(12);
    avlTree.insert(20);
    avlTree.insert(1);
    avlTree.insert(-2);

    // Search elements
    try
    {
        int found = avlTree.search(15);
        cout << "Found: " << found << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Count elements before removal of elements
    cout << "Number of elements: " << avlTree.count() << endl;

    // Remove elements
    avlTree.remove(7);
    avlTree.remove(1);

    // Count elements
    cout << "Number of elements: " << avlTree.count() << endl;

    // Insert a duplicate number which should throw an error
    avlTree.insert(20);
    return 0;
}
