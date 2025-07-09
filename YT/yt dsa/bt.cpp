bool ancestor(TreeNode* root,TreeNode* check){
    if(root == NULL) return nullptr;
    if(root == check)
    return root;
    ancestor(root->left , check);
    ancestor(root->right, check);
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr) return nullptr;
    if(ancestor(root,p) && ancestor(root,q))
    return root;
    else{
        while(root->left != NULL)
    }
}