#include <cassert>
#include <TreeForest/BinaryTree.h>

using namespace treeforest;

int main(){
    BinaryTree<int>* tree = new BinaryTree<int>();
    tree->add(5);
    tree->add(3);
    tree->add(100);
    tree->add(10);
    tree->add(12);
    assert(tree->find(12)==true);
    return 0;
}