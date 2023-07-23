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
    int BinaryTree<T>::remove(T value){

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

        if(current_node==nullptr) return 0;
        
        nodes::BinaryTreeNode<T>* parent_node = current_node->getParentNode();
        bool is_on_right = false;

        if(parent_node!=nullptr){
            if(parent_node->getLeftChild()!=nullptr && *(parent_node->getLeftChild())==*current_node){
                is_on_right = false;
                parent_node->unsetLeftChild();
            }else{
                is_on_right = true;
                parent_node->unsetRightChild();
            }
        }

        if(current_node->getLeftChild() == nullptr && current_node->getRightChild() == nullptr){ //leaf node
            delete current_node;
            return 1;
        }else if(current_node->getLeftChild() != nullptr && current_node->getRightChild() == nullptr){ // only left child
            if(parent_node!=nullptr){
                if(is_on_right){
                    parent_node->setRightChild(current_node->getLeftChild());
                }else{
                    parent_node->setLeftChild(current_node->getLeftChild());
                }
            }else{
                if(is_on_right){
                    this->root=current_node->getLeftChild();
                }else{
                    this->root=current_node->getLeftChild();
                }
            }
            delete current_node;
            return 1;
        }else if(current_node->getLeftChild() == nullptr && current_node->getRightChild() != nullptr){ // only right child
            if(parent_node!=nullptr){
                if(is_on_right){
                    parent_node->setRightChild(current_node->getRightChild());
                }else{
                    parent_node->setLeftChild(current_node->getRightChild());
                }
            }else{
                if(is_on_right){
                    this->root=current_node->getLeftChild();
                }else{
                    this->root=current_node->getLeftChild();
                }
            }
            delete current_node;
            return 1;
        }else{ //both children != nullptr
            nodes::BinaryTreeNode<T>* max_predecessor = current_node->getLeftChild();

            while(max_predecessor->getRightChild()!=nullptr){
                max_predecessor = max_predecessor->getRightChild();
            }

            if(*(max_predecessor->getParentNode())!=*current_node){
                max_predecessor->getParentNode()->setRightChild(max_predecessor->getLeftChild());
            }
            
            if(parent_node!=nullptr){
                if(is_on_right){
                    parent_node->setRightChild(max_predecessor);
                }else{
                    parent_node->setLeftChild(max_predecessor);
                }
            }else{
                this->root = max_predecessor;
            }

            if(*(max_predecessor->getParentNode())!=*current_node){
                max_predecessor->setLeftChild(current_node->getLeftChild());
            }

            max_predecessor->setRightChild(current_node->getRightChild());

            delete current_node;
            return 1;
        }
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