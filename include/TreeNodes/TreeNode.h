#ifndef TREENODE_H
#define TREENODE_H

namespace treeforest::nodes{
    /**
     * Class that represents a node of a tree
     * @typedef T type of the content of the node
    */
    template<typename T>
    class TreeNode{
        private:
            T* content;
            unsigned long children_size;
            TreeNode<T>** children;
            TreeNode<T>* parent_node;

        public:
            TreeNode() = delete; //remove default constructor
            /**
             * Constructor that creates an empty node
             * @param children_number max number of children that the node can handle
             * @param node_content pointer to the content of the current node (default nullptr)
             * @param parent_node pointer to the parent node (default nullptr)
            */
            TreeNode(const unsigned long children_number, T* node_content=nullptr, TreeNode<T>* parent_node=nullptr) : children_size(children_number), children(new TreeNode<T>*[children_number]), content(node_content), parent_node(parent_node){}
            
            /**
             * Method that set the content of the node
             * @param node_content pointer to the content of the node
            */
            void setContent(T* const node_content);
            /**
             * Method that return the content of the node
             * @return Content of the node
            */
            T* getContent();

            /**
             * Method that set the reference to the parent node
             * @param node pointer to the parent node
            */
            void setParentNode(TreeNode<T>* const node=nullptr);

            /**
             * Method that returns the reference to the parent node
             * @return reference to the parent node
            */
            TreeNode<T>* unsetParentNode();

            /**
             * Method that try to insert a node into a specific position
             * @param pos position in which the object will be inserted
             * @param node node to insert as children
             * @param force_replace if true, the node to insert replace eventually existing node (default to false)
             * @return -1 if the position passed is invalid
             * @return 0 if the object is correctly inserted
             * @return 1 if the given position is already occupied
            */
            int setChildrenNode(const int pos, TreeNode<T>* const node, bool force_replace=false);
            
            /**
             * Method that get the node in the specific position
             * @param pos position in which there is the node to retrieve
             * @return the node in the giving position, nullptr is the position is invalid or the node itself is nullptr
            */
            TreeNode<T>* getChildrenNode(const int pos);

            /**
             * Method that unset the node in the specific position
             * @param pos position in which there is the node to retrieve
             * @return the node in the giving position, nullptr is the position is invalid or the node itself is nullptr
            */
            TreeNode<T>* unsetChildrenNode(const int pos);

            /**
             * Method that delete the node in the specific position
             * @param pos position in which there is the node to retrieve
            */
            void deleteChildrenNode(const int pos);

            /**
             * Operator overload used to compare two nodes
             * @param node node to compare
             * @return true if the content of two nodes are equal, false otherwise
            */
            bool operator==(const TreeNode<T>& node) const;

            /**
             * Operator overload used to compare two nodes
             * @param node node to compare
             * @return true if the current node has a content bigger than the passed node, false otherwise
            */
            bool operator>(const TreeNode<T>& node) const;
            
            /**
             * Operator overload used to compare two nodes
             * @param node node to compare
             * @return true if the current node has a content smaller than the passed node, false otherwise
            */
            bool operator<(const TreeNode<T>& node) const;
            
            /**
             * Destructor of the class that destroy the content and set all pointers to nullptr
            */
            ~TreeNode(){
                parent_node=nullptr;
                for(int i=0;i<this->children_size;i++){
                    children[i]=nullptr;
                }
                delete content;
            }
    };

}

#include "TreeNode.hpp"

#endif