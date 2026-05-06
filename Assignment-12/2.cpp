#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int val) {
    if (root==nullptr) {
        return new Node(val);
    }
    if (val<root->data) {
        root->left=insert(root->left, val);
    }
    else {
        root->right=insert(root->right, val);
    }
    return root;
}

void inorder(Node *root) {
    if (root!=nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root!=nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root!=nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node *root=nullptr;
    int value;

    cout << "Enter 10 integer values:\n";
    for (int i=0; i<10; i++) {
        cout << "Value: " << i+1 << ": ";
        cin >> value;
        root=insert(root, value);
    }

    cout << "\nInorder traversal: ";
    inorder(root);

    cout << "\nPreorder traversal: ";
    preorder(root);

    cout << "\nPostorder traversal: ";
    postorder(root);
}