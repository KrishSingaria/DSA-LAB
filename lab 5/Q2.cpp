#include <vector>
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    std::vector<Node*> nodes;

public:
    BinaryTree() : nodes{} {}

    // Helper function to find the index of the last element
    int find_last_index() {
        int index = nodes.size() - 1;
        while (nodes[index]->right != nullptr) {
            index--;
        }
        return index;
    }

    void insert(int data) {
        Node* new_node = new Node(data);
        if (nodes.empty()) {
            nodes.push_back(new_node);
            return;
        }

        int current_index = 0;
        while (true) {
            if (data < nodes[current_index]->data) {
                if (nodes[current_index]->left == nullptr) {
                    nodes[current_index]->left = new_node;
                    nodes.push_back(new_node);
                    return;
                }
                current_index = current_index * 2 + 1;
            } else {
                if (nodes[current_index]->right == nullptr) {
                    nodes[current_index]->right = new_node;
                    nodes.push_back(new_node);
                    return;
                }
                current_index = current_index * 2 + 2;
            }
        }
    }

    void deleteNode(int data) {
        if (nodes.empty()) {
            return;
        }

        int current_index = 0;
        while (current_index < nodes.size()) {
            if (nodes[current_index]->data == data) {
                // Find the last element (bottom-most and rightmost)
                int last_index = find_last_index();

                // Swap data with the last element
                nodes[current_index]->data = nodes[last_index]->data;

                // Delete the last element (becomes a leaf node) by removing from vector
                delete nodes[last_index];
                nodes.erase(nodes.begin() + last_index);

                // Fix child pointers if needed (only if the deleted node had a child)
                if (current_index * 2 + 1 < nodes.size() && nodes[current_index]->left == nullptr) {
                    nodes[current_index]->left = nodes[last_index];
                } else if (current_index * 2 + 2 < nodes.size() && nodes[current_index]->right == nullptr) {
                    nodes[current_index]->right = nodes[last_index];
                }
                return;
            } else if (data < nodes[current_index]->data) {
                if (nodes[current_index]->left == nullptr) {
                    break;
                }
                current_index = current_index * 2 + 1;
            } else {
                if (nodes[current_index]->right == nullptr) {
                    break;
                }
                current_index = current_index * 2 + 2;
            }
        }
        // Not found
        std::cout << "Node with data " << data << " not found for deletion" << std::endl;
    }

    bool search(int data, int current_index = 0) {
        if (nodes.empty()) {
            return false;
        }
        if (current_index >= nodes.size()) {
            return false;
        }
        if (nodes[current_index]->data == data) {
            return true;
        } else if (data < nodes[current_index]->data) {
            return search(data, current_index * 2 + 1);
        } else {
            return search(data, current_index * 2 + 2);
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6); 

    tree.deleteNode(4);

    if (tree.search(4)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
}