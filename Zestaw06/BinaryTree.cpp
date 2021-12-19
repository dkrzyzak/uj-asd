#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    BinaryTree bt = BinaryTree();
    int elementsCount;
    cin >> elementsCount;

    int x;
    for (int i = 0; i < elementsCount; i++) {
        cin >> x;
        bt.insert(x);
    }

    cout << bt.size() << " " << bt.depth(bt.getRoot()) << " " << bt.minimum() << " " << bt.maximum() << endl;

    bt.preorder(bt.getRoot());

    for (int number = 1; number < 10; number++) {
        // cout << ((bt.searchRecursive(number, bt.getRoot()) == nullptr) ? "No" : "Yes") << endl;
        cout << ((bt.search(number) == nullptr) ? "No" : "Yes") << endl;
    }
    
    return 0;
}
