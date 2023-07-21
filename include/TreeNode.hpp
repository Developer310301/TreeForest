namespace treeforest{

    template<typename T>
    void TreeNode<T>::setContent(T* const node_content){
        this->content = node_content;
    }

    template<typename T>
    T* TreeNode<T>::getContent(){
        return this->content;
    }

    template<typename T>
    void TreeNode<T>::setParentNode(TreeNode<T>* const node){
        this->parent_node = node;
    }

    template<typename T>
    T* TreeNode<T>::unsetParentNode(){
        TreeNode<T>* p = this->parent_node;
        this->parent_node = nullptr;
        return p;
    }

    template<typename T>
    int TreeNode<T>::setChildrenNode(const int pos, TreeNode<T>* const node, bool force_replace=false){
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
    T* TreeNode<T>::unsetChildrenNode(const int pos){
        if(pos<0 || pos>=this->children_size){
            return nullptr;
        }

        return this->children[pos];
    }

    template<typename T>
    bool TreeNode<T>::operator==(TreeNode<T> const node) const{
        return this->content==node;
    }

    template<typename T>
    bool TreeNode<T>::operator>(TreeNode<T> const node) const{
        return this->content>node;
    }

    template<typename T>
    bool TreeNode<T>::operator<(TreeNode<T> const node) const{
        return this->content<node;
    }

}