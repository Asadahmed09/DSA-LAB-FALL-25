#include <iostream>
using namespace std;

class node {
public:
    node* left;
    node* right;
    int val;
    node(int v): val(v), left(NULL), right(NULL) {}
};

node* CreateNode(int v) {
    return new node(v);
}

void insertLeft(node* root, int v) {
    if(root->left == NULL) {
        root->left = new node(v);
        return;
    }
    insertLeft(root->left, v);
}

void insertRight(node* root, int v) {
    if(root->right == NULL) {
        root->right = new node(v);
        return;
    }
    insertRight(root->right, v);
}

void display(node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

void displayLeaves(node* root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        cout << root->val << " ";
        return;
    }
    displayLeaves(root->left);
    displayLeaves(root->right);
}

int treeHeight(node* root) {
    if(root == NULL) return -1;
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return 1 + (lh > rh ? lh : rh);
}

void printLevels(node* root, int level = 0) {
    if(root == NULL) return;
    cout << root->val << " " << level << endl;
    printLevels(root->left, level + 1);
    printLevels(root->right, level + 1);
}

int main() {
    node* root = CreateNode(60);
    insertLeft(root, 45);
    insertRight(root, 42);
    insertLeft(root->left, 25);
    insertRight(root->left, 26);
    insertLeft(root->right, 20);
    insertRight(root->right, 22);

    cout << "Root: " << root->val << endl;
    cout << "Leaf nodes: ";
    displayLeaves(root);
    cout << endl;
    cout << "Height of tree: " << treeHeight(root) << endl;
    cout << "Levels:\n";
    printLevels(root);
}
