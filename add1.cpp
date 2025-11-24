#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left,
Node *right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

bool isLeaf(Node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

int sumOfLeftLeaves(Node* root) {
    if (root == NULL) return 0;

    int sum = 0;

    if (isLeaf(root->left))
        sum += root->left->val;

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of all left leaves = " << sumOfLeftLeaves(root);
    return 0;
}
