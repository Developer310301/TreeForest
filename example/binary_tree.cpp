#include <Arduino.h>
#include <TreeForest/BinaryTree.h>

using namespace treeforest;

BinaryTree<int> tree;

void setup(){
    tree.add(23);
    tree.add(234);
    tree.add(-23);
}

void loop(){
    ///Perfom operations on BST
}