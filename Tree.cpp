#include "Tree.h" 
using namespace std;
void BTree::Add(int key, double data) { //добавление
    if (root == nullptr) {
        root = new Node(key, data);
    }
    else {
        Node* current = root;
        while (true) {
            if (key == current->key) {
                return;
            }
            if (key < current->key) {
                if (current->left == nullptr) {
                    current->left = new Node(key, data);
                    current->left->parent = current;
                    return;
                }
                current = current->left;
            }
            else {
                if (current->right == nullptr) {
                    current->right = new Node(key, data);
                    current->right->parent = current;
                    return;
                }
                current = current->right;
            }
        }
    }
}
Node* BTree::find(int inkey) { // поиск
    Node* current = root;
    while (current != nullptr) {
        if (current->key == inkey) {
            break;
        }
        if (current->key > inkey) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return current;
}
void BTree::order() {
    order2(root);
}
void BTree::order2(Node* node) {
    if (node == nullptr) {
        return;
    }
    order2(node->right);
    printNodeInfo(node);
    order2(node->left);


}

Node* BTree::min() { // минимум 
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
Node* BTree::max() { // максимум 
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}
int BTree::remove(int inkey) { // удаление
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        if (current->key == inkey) {
            break;
        }
        if (current->key > inkey) {
            parent = current;
            current = current->left;
        }
        else {
            parent = current;
            current = current->right;
        }
    }
    if (current->left == nullptr && current->right == nullptr) {
        if (current == parent->right) {
            parent->right = nullptr;
        }
        if (current == parent->left) {
            parent->left = nullptr;
        }
        delete current;
        return 0;
    }
    else if (current->left == nullptr || current->right == nullptr) { //один потомок
        if (current == parent->right) {
            parent->right = parent->left;
        }
        if (current == parent->left) {
            parent->left = parent->right;
        }
        delete current;
        return 0;
    }
    else { // два потомка
        Node* change_el = current->right;
        while (change_el->left != nullptr) {
            change_el = change_el->left;
        }
        if (current == parent->right) {
            parent->right = change_el;
        }
        if (current == parent->left) {
            parent->left = change_el;
        }
        remove(change_el);
        delete current;
        return 0;
    }
}

double BTree::summm() {
    int count = 0;
    double tmp = summ(root, &count);
    return tmp / count;
}

double BTree::summ(Node* node, int* i) { // cумма узлов
    if (node == nullptr) {
        return 0;
    }
    (*i)++;
    double right = summ(node->right, i);
    double left = summ(node->left, i);
    //if (node->data >= 500) {
        //return right + left;
    //}

    return (node->data + right + left);
}
void BTree::inorder() {
    inorderTraversal(root);
}
void BTree::inorderTraversal(Node* node) { // сортировка
    if (node == nullptr) { return; }
    inorderTraversal(node->left);
    cout << node->key << " ";
    inorderTraversal(node->right);

}

void BTree::printNodeInfo(Node* node) { //метод вывода 
    if (node == nullptr) {
        return;
    }
    cout << " Ключ узла: " << node->key;
    if (node->left != nullptr) {
        cout << " Левый потомок: " << node->left->key;
    }
    else {
        cout << " Левого потомка нет";
    }
    if (node->right != nullptr) {
        cout << " Правый потомок: " << node->right->key;
    }
    else {
        cout << " Правого потомка нет";
    }
    cout << endl;
};
