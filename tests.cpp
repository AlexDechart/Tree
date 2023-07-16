#include <iostream>
#include "Tree.h" 
using namespace std;
void testfind(BTree* tree) {
    Node* n = tree->find(20);
    if (n != nullptr) {
        cout << n->key << endl;
    }
    else {
        cout << "Узла не существует" << endl;
    }

}
void mintest(BTree& tree) {
    cout << tree.min()->key << endl;
}
void maxtest(BTree& tree) {
    cout << tree.max()->key << endl;
}