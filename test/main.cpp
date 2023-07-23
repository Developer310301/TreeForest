#include <stdio.h>
#include <TreeForest/BinaryTree.h>

using namespace treeforest;

int main(){

    BinaryTree<int>* tree = new BinaryTree<int>();

    int num=5;
    int num1=10;
    int num2=3;
    int num3=15;
    int num4=12;
    tree->add(num);
    tree->add(num2);
    tree->add(num1);
    tree->add(num3);
    tree->add(num4);
    int* node = tree->get(num2);
    tree->remove(num3);
    printf("Node content : %d\n", *node);

    return 0;
}