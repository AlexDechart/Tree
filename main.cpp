#include <iostream>
#include "Tree.h" 
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    BTree tree;
    tree.Add(17, 300);
    tree.Add(10, 100);
    tree.Add(54, 400);
    tree.Add(7, 700);
    tree.Add(13, 500);
    tree.Add(9, 600);

    tree.order();
    cout << "--------------------------" << endl;
    tree.remove(7); //удаление
    tree.order();
}