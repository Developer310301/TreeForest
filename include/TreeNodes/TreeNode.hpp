namespace treeforest::nodes{

    template<typename T>
    void TreeNode<T>::setContent(T const node_content){
        this->content = node_content;
    }

    template<typename T>
    T* TreeNode<T>::getContent(){
        return &this->content;
    }

    template<typename T>
    void TreeNode<T>::setParentNode(TreeNode<T>* const node){
        this->parent_node = node;
    }

    template<typename T>
    TreeNode<T>* TreeNode<T>::unsetParentNode(){
        TreeNode<T>* p = this->parent_node;
        this->parent_node = nullptr;
        return p;
    }

    template<typename T>
    int TreeNode<T>::setChildrenNode(const int pos, TreeNode<T>* const node, bool force_replace){
        if(pos<0 || pos>=this->children_size){
            return -1;
        }

        if(this->children[pos]==nullptr || force_replace==true){
            this->children[pos]=node;
            return 0;
        }else{
            return 1;
        }

    }

    template<typename T>
    TreeNode<T>* TreeNode<T>::getChildrenNode(const int pos){
        if(pos<0 || pos>=this->children_size){
            return nullptr;
        }

        return this->children[pos];
    }

    template<typename T>
    TreeNode<T>* TreeNode<T>::unsetChildrenNode(const int pos){
        if(pos<0 || pos>=this->children_size){
            return nullptr;
        }
        TreeNode<T>* n = this->children[pos];
        this->children[pos] = nullptr;
        return n;
    }

    template<typename T>
    void TreeNode<T>::deleteChildrenNode(const int pos){
        if(pos>=0 && pos<this->children_size && this->children[pos]|=nullptr){
            delete this->children[pos];
        }
    }

    template<typename T>
    bool TreeNode<T>::operator==(const TreeNode<T>& node) const{
        return this->content == node.content;
    }

    template<typename T>
    bool TreeNode<T>::operator!=(const TreeNode<T>& node) const{
        return this->content != node.content;
    }


    template<typename T>
    bool TreeNode<T>::operator>(const TreeNode<T>& node) const{
        return this->content > node.content;
    }

    template<typename T>
    bool TreeNode<T>::operator<(const TreeNode<T>& node) const{
        return this->content < node.content;
    }

}