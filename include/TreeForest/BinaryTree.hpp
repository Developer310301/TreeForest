namespace treeforest{

    template<typename T>
    nodes::BinaryTreeNode<T>* BinaryTree<T>::add(T value){

        nodes::BinaryTreeNode<T>* added_node = new nodes::BinaryTreeNode<T>(value);

        if(this->root==nullptr){ //empty tree
            this->root = added_node;
            return added_node;
        }

        nodes::BinaryTreeNode<T>* current_node = this->root;
        nodes::BinaryTreeNode<T>* parent_node = this->root->getParentNode();

        bool is_on_right = false;

        while(current_node!=nullptr){
            if(*current_node == *added_node){
                delete added_node;
                return nullptr;
            }else if(*current_node > *added_node){
                parent_node = current_node;
                current_node = (nodes::BinaryTreeNode<T>*)current_node->getLeftChild();
                is_on_right = false;
            }else{
                parent_node = current_node;
                current_node = (nodes::BinaryTreeNode<T>*)current_node->getRightChild();
                is_on_right = true;
            }

        }

        added_node->setParentNode(parent_node);
        
        if(is_on_right){
            parent_node->setRightChild(added_node);
        }else{
            parent_node->setLeftChild(added_node);
        }

        return added_node;

    }

    template<typename T>
    int BinaryTree<T>::find(T value){
        return (this->get(value)!=nullptr) ? 1 : 0;
    }

    template<typename T>
    T* BinaryTree<T>::get(T value){
        
        nodes::BinaryTreeNode<T>* test_node = new nodes::BinaryTreeNode<T>(value);
        nodes::BinaryTreeNode<T>* current_node = this->root;

        while(current_node!=nullptr){

            if(*current_node == *test_node){
                break;
            }else if(*current_node > *test_node){
                current_node = current_node->getLeftChild();
            }else{
                current_node = current_node->getRightChild();
            }

        }

        delete test_node;
        return current_node->getContent();

    }

}