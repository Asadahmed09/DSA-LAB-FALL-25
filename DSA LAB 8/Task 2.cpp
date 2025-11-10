#include <iostream>
using namespace std;

class Node {
public:
    int playCount;
    string song;
    Node* left;
    Node* right;
    Node(int p, string s) {
        playCount = p;
        song = s;
        left = right = NULL;
    }
};

Node* insert(Node* root, int p, string s) {
    if (root == NULL)
        return new Node(p, s);
    if (p < root->playCount)
        root->left = insert(root->left, p, s);
    else
        root->right = insert(root->right, p, s);
    return root;
}

Node* search(Node* root, int p) {
    if (root == NULL || root->playCount == p)
        return root;
    if (p < root->playCount)
        return search(root->left, p);
    else
        return search(root->right, p);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->song << " (" << root->playCount << ")" << endl;
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->song << " (" << root->playCount << ")" << endl;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int p) {
    if (root == NULL)
        return root;
    if (p < root->playCount)
        root->left = deleteNode(root->left, p);
    else if (p > root->playCount)
        root->right = deleteNode(root->right, p);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->playCount = temp->playCount;
        root->song = temp->song;
        root->right = deleteNode(root->right, temp->playCount);
    }
    return root;
}

int main() {
    Node* root = NULL;

    root = insert(root, 120, "Song A");
    root = insert(root, 300, "Song B");
    root = insert(root, 90, "Song C");
    root = insert(root, 450, "Song D");
    root = insert(root, 200, "Song E");

    cout << "Inorder (Least to Most Played):" << endl;
    inorder(root);

    cout << "Postorder ---- Reverse Popularity ----- :" << endl;
    postorder(root);

    cout << "Search for play count 200:" << endl;
    Node* found = search(root, 200);
    if (found)
        cout << found->song << " found with play count " << found->playCount << endl;
    else
        cout << "Not found" << endl;

    cout << "Delete song with play count 300:" << endl;
    root = deleteNode(root, 300);
    inorder(root);

}
