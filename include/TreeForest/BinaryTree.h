#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNodes/BinaryTreeNode.h"

namespace treeforest{
    /**
     * Class that implement a Binary Search Tree
     * @typedef T generic type relative to the @ref{nodes::BinaryTreeNode} class content attribute
    */
    template<typename T>
    class BinaryTree{
        private:
            /**
             * Root node of the tree
            */
            nodes::BinaryTreeNode<T>* root;
        
        public:
            /**
             * Default constructor that creates an empty binary tree
            */
            BinaryTree() : root(nullptr){}

            /**
             * Method that will add a reference to a T type object to the tree, only if the pointer is not nullptr
             * @param value object to add to the tree
             * @return reference to the node where the object is placed
            */
            nodes::BinaryTreeNode<T>* add(T value);

            /**
             * Method that will remove AND ERASE the passed object from the tree
             * @param value object to delete from the tree
             * @return 0 if the object is not found or uncapeable to delete;
             * @return 1 if the object is correctly deleted
            */
            int remove(T value);

            /**
             * Method that find a specific value in the tree
             * @param value object to find in the tree
             * @return 0 if the object doesn't exist in the tree;
             * @return 1 if the passed object is found
            */
            int find(T value);

            /**
             * Method that get a reference to a specific object in the tree
             * @param value object to find and retrieve
             * @return object found;
             * @return nullptr if the passed object doesn't exist in the tree
            */
            T* get(T value);
            
    };
}

#include "TreeForest/BinaryTree.hpp"

#endif