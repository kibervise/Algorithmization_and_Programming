#include <iostream>
using namespace std;

/*Structure of each node in the tree*/
struct node
{
    int data;
    node *left;
    node *right;
};


/*This function is used to create and
 initialises new nodes*/
node *NewNode(int key)
{
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = key;
    return temp;
}

/*This funciton is used to Insert
 new values in BST*/
node *Insert(node *root,int key) //--------------
{
    if(root == NULL)
    {
        return NewNode(key);
    }
    if(key < root->data)
    {
        root->left = Insert(root->left,key);
    }
    else
    {
        root->right = Insert(root->right,key);
    }
    return root;
}

/*This function is used to
 print Inorder traversal / выводит в порядке пересечения*/
void Inorder(node *root) //************
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout << root-> data << " ";
    Inorder(root->right);
}

node* Min(node *root)
{
    if(root->left == NULL)
    {
        return root;
    }
    return Min(root->left);
}

node* Max(node *root)
{
    if(root->right == NULL)
    {
        return root;
    }
    return Max(root->right);
}

void Swap(node *root)
{
    if(root == NULL)
        return;
    
    int tmp;
    node *f = Min(root);
    node *s = Max(root);
    
    /* swap pointers */
    tmp = s->data;
    s->data = f->data;
    f->data = tmp;
}

void Free(node *&root)
{
    if (root->left)
    {
        Free(root->left);
    }
    
    if (root->right)
    {
        Free(root->right);
    }
    delete root;
}

void Action()
{
    node* root = NULL;
    int root_num;
    cout << "Enter the number of roots: ";
    cin >> root_num;
    for (int i = 0; i < root_num; ++i)
    {
        cout << "Insert key: ";
        int key;
        cin >> key;
        root = Insert(root, key);
    }
    
    cout << "Nodes in the tree: ";
    Inorder(root);
    
    Swap(root);
    
    cout << "\nSwap min and max nodes in the tree: ";
    Inorder(root);
    
    cout << endl;
    
    Free(root);
}

int main()
{
    Action();
}
