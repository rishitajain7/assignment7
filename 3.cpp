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
    }
};

Node* insert(Node* root, int x){
    if(!root) {
      return new Node(x);}
    if(x < root->data) {
      root->left = insert(root->left, x);}
    else if(x > root->data) {
      root->right = insert(root->right, x);}
    return root;
}

Node* minNode(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(!root) return NULL;

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if(!root->left){
            return root->right;
        }
        else if(!root->right) {
            return root->left;
        }
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Max depth
int maxDepth(Node* root){
    if(!root) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Min depth
int minDepth(Node* root){
    if(!root) {
        return 0;
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root =NULL;
    root =insert(root, 20);
    insert(root, 10);
    insert(root, 30) ;

    root =deleteNode(root, 10);

    cout<< "Max Depth: " << maxDepth(root);
    cout<< "\nMin Depth: " << minDepth(root);

    return 0;
}
