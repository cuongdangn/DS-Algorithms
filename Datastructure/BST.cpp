#include <bits/stdc++.h>

using namespace std;

struct tree_node{
       tree_node* left;
       tree_node* right;
       tree_node* parrent;
       int data;
       int child;
       int height;
};
class BinarySearchTree
{

    public:
        tree_node* root;

        BinarySearchTree()
        {
           root = NULL;
        }

        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert(int);
        tree_node* deleteNode(tree_node*,int);
        tree_node* find(int);
        tree_node* minValueNode(tree_node*);
        tree_node* maxValueNode(tree_node*);
        tree_node* kthMaxValueNode(tree_node*,int);
};

// Smaller elements go left
// larger elements go right
tree_node* BinarySearchTree::kthMaxValueNode(tree_node* r,int k)
{
    if(r==NULL)
        return r;
    int numl = 0;
    if(r->left)
        numl = r->left->child;
    if(k-numl == 1)
        return r;
    if(k-numl > 1)
        return kthMaxValueNode(r->right,k-numl-1);
    else
        return kthMaxValueNode(r->left,k);
}
tree_node* BinarySearchTree::find(int d)
{
    tree_node* crr = root;
    while(crr!=NULL){
        if(crr->data==d)
            return crr;
        if(crr->data<d)
            crr = crr->right;
        else
            crr = crr->left;
    }
    return NULL;
}
void BinarySearchTree::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    t->parrent = NULL;
    t->child = 1;
    t->height = 0;
    parent = NULL;

    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            curr->child++;
            curr->height++;
            if(t->data > curr->data)
                    curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
        t->parrent = parent;
    }
}

tree_node * BinarySearchTree::minValueNode(tree_node* node)
{
    tree_node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

tree_node * BinarySearchTree::maxValueNode(tree_node* node)
{
    tree_node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->right != NULL)
        current = current->right;

    return current;
}
tree_node* BinarySearchTree::deleteNode(tree_node *root,int key)
{
    //Locate the elemen
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            tree_node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree_node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        tree_node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;


}

void BinarySearchTree::print_inorder()
{
  inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
    preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_postorder()
{
    postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else return;
}



int n;
int a[100];
BinarySearchTree tree;
int main()
{
    freopen("code.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //cout << a;
        tree.insert(a[i]);

    }
    for(int i=1;i<=n;i++)
        cout << tree.find(a[i])->height<<endl;
  //  tree.deleteNode(tree.root,5);
    //test kthMaxValueNode
    /*for(int i=1;i<=n;i++){
        tree_node* kt = tree.kthMaxValueNode(tree.root,i);
        if(kt!=NULL)
            cout << kt->data << endl;
    }*/
    //test height
   // cout << tree.find(5)->height<< " height"<<endl;


    tree.print_inorder();
}
