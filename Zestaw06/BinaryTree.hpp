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

    // INTERNAL METHODS

    Node* _searchRecursive(int x, Node* node) {
        if (node == nullptr || node->key == x) {
            return node;
        }

        if (x < node->key) {
            return _searchRecursive(x, node->left);
        }

        return _searchRecursive(x, node->right);
    }

    int _depth(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int lDepth = _depth(node->left);
        int rDepth = _depth(node->right);

        if (lDepth > rDepth) {
            return lDepth + 1;
        }

        return rDepth + 1;
    }

    void _inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        _inorder(node->left);
        cout << node->key << endl;
        _inorder(node->right);
    }

    void _preorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->key << endl;
        _preorder(node->left);
        _preorder(node->right);
    }
    void _postorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        _postorder(node->left);
        _postorder(node->right);
        cout << node->key << endl;
    }


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

    Node* searchRecursive(int x) {
        return _searchRecursive(x, root);
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

    int depth() {
        return _depth(root);
    }

    void inorder() {
        return _inorder(root);
    }

    void preorder() {
        return _preorder(root);
    }
    void postorder() {
        return _postorder(root);
    }
};

#endif
