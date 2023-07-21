#ifndef TREENODE_H
#define TREENODE_H

namespace treeforest{

    template<typename T>
    class TreeNode{
        private:
            T* content;
            unsigned long children_size;
            TreeNode<T>** children;
            TreeNode<T>* parent_node;

        public:
            TreeNode(const unsigned long children_number, T* node_content=nullptr, T* parent_node=nullptr) : children_size(children_number), children(new TreeNode<T>[children_number]), content(node_content), parent_node(parent_node){}
            void setContent(T* node_content);
            T* getContent();
            void setParentNode(TreeNode<T>* node=nullptr);
            void deleteParentNode();
            int setChildrenNode(int pos, TreeNode<T>* node=nullptr);
            int deleteChildrenNode(int pos);
            bool operator==(TreeNode<T> const node) const;
            bool operator>(TreeNode<T> const node) const;
            bool operator<(TreeNode<T> const node) const;
            ~TreeNode(){
                parent_node=nullptr;
                for(int i=0;i<this->children_size;i++){
                    children[i]=nullptr;
                }
                delete content;
            }
    };

    #include "TreeNode.hpp"

}

#endif