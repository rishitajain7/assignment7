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
    if(!root) return new Node(x);
    if(x < root->data) root->left = insert(root->left, x);
    else if(x > root->data) root->right = insert(root->right, x);
    return root;
}

// Recursive search
Node* searchRec(Node* root, int key){
    if(!root || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Non-recursive search
Node* searchNonRec(Node* root, int key){
    while(root){
        if(root->data == key) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// Min
Node* minimum(Node* root){
    while(root->left) root = root->left;
    return root;
}

// Max
Node* maximum(Node* root){
    while(root->right) root = root->right;
    return root;
}

// Inorder Successor
Node* inorderSuccessor(Node* root, Node* x){
    if(x->right) return minimum(x->right);
    Node* succ = NULL;
    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else if(x->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

// Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* x){
    if(x->left) return maximum(x->left);
    Node* pred = NULL;
    while(root){
        if(x->data > root->data){
            pred = root;
            root = root->right;
        } else if(x->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
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

    cout<< "\nSuccessor of 10: " << inorderSuccessor(root, searchRec(root, 10))->data;

    cout<< "\nPredecessor of 20: " << inorderPredecessor(root, searchRec(root, 20))->data;

    return 0;
}
