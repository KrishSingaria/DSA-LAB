#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int key;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* insert(BinaryTreeNode* root, int key) {
    if (root == nullptr) {
        root = new BinaryTreeNode();
        root->key = key;
    }
    else if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

BinaryTreeNode* findMin(BinaryTreeNode* node) {
    while (node->left!= nullptr) {
        node = node->left;
    }

    return node;
}

BinaryTreeNode* deleteNode(BinaryTreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node to be deleted is found

        if (root->left == nullptr) {
            return root->right;
        }
        else if (root->right == nullptr) {
            return root->left;
        }

        BinaryTreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

bool search(BinaryTreeNode* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (key < root->key) {
        return search(root->left, key);
    }
    else if (key > root->key) {
        return search(root->right, key);
    }
    else {
        return true;
    }
}

int main() {
    BinaryTreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    deleteNode(root, 60);

    if (search(root, 50)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}