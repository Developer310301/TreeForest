#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include "TreeNodes/TreeNode.h"

namespace treeforest::nodes{

    /**
     * Class that implement the @ref{TreeNode} class in order to
     * create a node that will be used into a binary tree
     * @tparam T type of the content of the node
    */
    template<typename T>
    class BinaryTreeNode : public TreeNode<T>{

        public:
            /**
             * Constructor that creates an empty binary node
             * @param node_content content of the current node
             * @param parent_node reference of parent node
            */
            BinaryTreeNode(T node_content=nullptr, TreeNode<T>* parent_node=nullptr) : TreeNode<T>(2,node_content,parent_node){}

            /**
             * Method that set the left child of the current node
             * @param node node to insert
            */
            int setLeftChild(BinaryTreeNode<T>* node) { return this->setChildrenNode(0, node, true); }

            /**
             * Method that get the left child of the current node
             * @return left child node
            */
            BinaryTreeNode<T>* getLeftChild() { return (BinaryTreeNode<T>*)this->getChildrenNode(0); }

            /**
             * Method that unset the left child of the current node
             * @return left child node that will be unsetted
            */
            BinaryTreeNode<T>* unsetLeftChild() { return (BinaryTreeNode<T>*)this->unsetChildrenNode(0); }

            /**
             * Method that set the right child of the current node
             * @param node node to insert
            */
            int setRightChild(BinaryTreeNode<T>* node) { return this->setChildrenNode(1, node, true); }

            /**
             * Method that get the right child of the current node
             * @return right child node
            */
            BinaryTreeNode<T>* getRightChild() { return (BinaryTreeNode<T>*)this->getChildrenNode(1); }

            /**
             * Method that unset the right child of the current node
             * @return right child node that will be unsetted
            */
            BinaryTreeNode<T>* unsetRightChild() { return (BinaryTreeNode<T>*)this->unsetChildrenNode(1); }

            /**
             * Method that get the parent node
             * @return pointer to the parent node
            */
            BinaryTreeNode<T>* getParentNode() { return (BinaryTreeNode<T>*)TreeNode<T>::getParentNode(); }

    };

}

#endif