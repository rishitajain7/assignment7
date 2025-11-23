#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, 
Node *right;
    Node(int x){
      data = x; 
      left = right = NULL;
    }};

bool isBST(Node* root, int minVal, int maxVal){
    if(!root) return true;
    if(root->data < minVal || root->data > maxVal) return false;
    return isBST(root->left, minVal, root->data - 1) &&
           isBST(root->right, root->data + 1, maxVal);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    if(isBST(root, -9999, 9999))
        cout << "Valid BST";
    else
        cout << "Not a BST";

    return 0;
}
