((1)) Least common Ancestor in Binary Search Tree 

node * lca(node * root, int v1,int v2)
{
    if(root==NULL)
        return root;
    
    if(root->data < v1 && root->data < v2) {
        return lca(root->right , v1,v2);
    }
    else if(root->data > v1 && root->data > v2){
        return lca(root->left , v1,v2);
    }
    else
        return root;
}


((2)) LCA for Binary tree
node *lca(node *head , node *a,node *b) {

    if(head==NULL)
        return NULL;

    if(head==a || head==B)
        return head;

    node *left=lca(head->left,a,b);
    node *right=lca(head->right,a,b);

    if(left!=NULL && right!=NULL)
        return head;

    if(left==NULL)
        return right;
    else
        return left;
}
