#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* minValueNode(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr) current = current->left;
    return current;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = nullptr;
    int arr[] = {15, 18, 61, 25, 260, 1, 20, 10, 3, 30};
    for (int i = 0; i < 10; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    root = deleteNode(root, 10);
    cout << "\nTree after deleting 10:" << endl;
    inorder(root);
    cout << endl;

    int arrA[] = {2, 8, 15, 30, 45, 60, 80};
    Node* rootA = nullptr;
    for (int i = 0; i < 7; i++) {
        rootA = insert(rootA, arrA[i]);
    }
    cout << "Height of tree A: " << height(rootA) << endl;

    int arrB[] = {30, 15, 45, 8, 60, 2, 80};
    Node* rootB = nullptr;
    for (int i = 0; i < 7; i++) {
        rootB = insert(rootB, arrB[i]);
    }
    cout << "Height of tree B: " << height(rootB) << endl;

    return 0;
}