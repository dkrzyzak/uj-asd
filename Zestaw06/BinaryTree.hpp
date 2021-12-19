#ifndef BINARYTREE
#define BINARYTREE

using namespace std;

class BinaryTree {
    private:
    struct Node {
        int key;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(): key(0) {};
        Node(int key): key(key) {};
    };

    Node* root = nullptr;
    int nodesCount = 0;


    public:
    BinaryTree() {}

    void insert(int x) {
        auto newNode = new Node(x);
        nodesCount++;

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* prev = nullptr;
        Node* temp = root;

        while (temp != nullptr) {
            if (x < temp->key) {
                prev = temp;
                temp = temp->left;
            } else {
                prev = temp;
                temp = temp->right;
            }
        }

        if (x < prev->key) {
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
    }

    Node* search(int x) {
        Node* prev = nullptr;
        Node* temp = root;

        while (temp != nullptr && temp->key != x) {
            if (x < temp->key) {
                prev = temp;
                temp = temp->left;
            } else {
                prev = temp;
                temp = temp->right;
            }
        }
        
        return temp;
    }

    Node* searchRecursive(int x, Node* node) {
        if (node == nullptr || node->key == x) {
            return node;
        }

        if (x < node->key) {
            return searchRecursive(x, node->left);
        }

        return searchRecursive(x, node->right);
    }

    int size() {
        return nodesCount;
    }

    int minimum() {
        Node* prev = nullptr;
        Node* temp = root;

        while (temp != nullptr) {
            prev = temp;
            temp = temp->left;
        }

        return prev->key;
    }

    int maximum() {
        Node* prev = nullptr;
        Node* temp = root;

        while (temp != nullptr) {
            prev = temp;
            temp = temp->right;
        }

        return prev->key;
    }

    int depth(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int lDepth = depth(node->left);
        int rDepth = depth(node->right);

        if (lDepth > rDepth) {
            return lDepth + 1;
        }

        return rDepth + 1;
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);
        cout << node->key << endl;
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->key << endl;
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->key << endl;
    }

    Node* getRoot() {
        return root;
    }
};

#endif
