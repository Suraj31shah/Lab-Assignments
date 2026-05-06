#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *buildTree(int pre[], int lpre, int hpre, int in[], int lin, int hin) {
    if (lpre<=hpre) {
        Node *root=new Node(pre[lpre]);
        int i=0;
        for (i=lin; i<=hin; i++) {
            if (pre[lpre]==in[i]) {
                break;
            }
        }
        int size=i-lin;
        root->left=buildTree(pre, lpre+1, lpre+size, in, lin, lin+size-1);
        root->right=buildTree(pre, lpre+size+1, hpre, in, lin+size+1, hin);
        return root;
    }
    return nullptr;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int inorder[]={1, 8, 19, 13, 25, 9, 5, 10, 4, 3};
    int preorder[]={25, 8, 1, 13, 19, 5, 9, 4, 10, 3};
    Node *root=nullptr;
    int n=sizeof(inorder)/sizeof(inorder[0]);

    root=buildTree(preorder, 0, n-1, inorder, 0, n-1);
    
    cout << "Inorder (from built tree): ";
    inorderTraversal(root);

    cout << "\nPreorder (from built tree): ";
    preorderTraversal(root);

    cout << endl;
}