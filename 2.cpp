#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Insertingg
Node* insert(Node* root, int x){
    if(!root) {
        return new Node(x);
    }
    if(x < root->data) {
        root->left = insert(root->left, x);
    }
    else if(x > root->data) {
        root->right = insert(root->right, x);
    }
    return root;
}


Node* searchRec(Node* root, int key){
    if(!root || root->data == key) {
        return root;
    }
    if(key < root->data) {
        return searchRec(root->left, key);
    }
    return searchRec(root->right, key);
}

// Minimum element to the left 
Node* minimum(Node* root){
    while(root->left) root = root->left;
    return root;
}

// Max element to the right 
Node* maximum(Node* root){
    while(root->right) root = root->right;
    return root;
}


int main(){
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);

    Node* s = searchNonRec(root, 10);
    if(s) cout << "Found: " << s->data;

    cout<< "\nMin: " << minimum(root)->data;
    cout<< "\nMax: " << maximum(root)->data;
}

    cout<< "\nPredecessor of 20: " << inorderPredecessor(root, searchRec(root, 20))->data;

    return 0;
}
