#include <iostream>
class Node {
public:
    int key;
    double data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int inkey = 0, double indata = 0) : key(inkey), data(indata), left(nullptr), right(nullptr), parent(nullptr) {}
};
class BTree {
private:
    Node* root;

public:
    BTree() : root(nullptr) {}
    void Add(int key, double data);//добавление
    Node* find(int inkey); //поиск
    void order(); //вывод в порядке возрастания
    void order2(Node* node);
    Node* min(); //минимум
    Node* max(); //максимум
    int remove(int key); //удаление
    double summm(); //сумма
    double summ(Node* node, int* i);
    void inorder(); //еще вариация вывода
    void inorderTraversal(Node* node);
    void printNodeInfo(Node* node); //метод вывода
};