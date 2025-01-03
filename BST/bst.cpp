#include <iostream>
#include <queue>
#include<stack>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
    Node(int item)
    {
        key = item;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node *insert(Node *root, int x)
{

    Node *temp = new Node(x);

    // If tree is empty
    if (root == NULL)
        return temp;

    // Find the node who is going
    // to have the new node temp as
    // it child. The parent node is
    // mainly going to be a leaf node
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root;
    }

    // If x is smaller, make it
    // left child, else right child
    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}

Node *search(Node *root, int key)
{

    // Base Cases: root is null or key
    // is present at root
    if (root == NULL || root->key == key)
        return root;

    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp;
        }
        if (temp->key < key)
        {
            temp = temp->right;
        }
        if (temp->key > key)
        {
            temp = temp->left;
        }
    }
    return NULL;
}

Node *recursive_search(Node *root,int key)
{
    if (root == NULL || root->key == key)
        return root;
    if(root->key > key){
        recursive_search(root->left,key);
    }
    else{
        recursive_search(root->right,key);
    }
}

Node* minValueNode(Node* root) {
    // The leftest node of any subtree is minimum
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* maxValueNode(Node* root) {
    // The rightest node of any subtree is maximum
    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

void delete_node(Node *root, int key)
{
    Node *d = search(root, key);
    if (d)
    { // if the node exists

        // Case-1: leaf node
        if (d->left == NULL && d->right == NULL)
        {

            if (d->parent)
            {
                if (d->parent->key > d->key)
                    d->parent->left = NULL;
                else
                    d->parent->right = NULL;
            }

            d = NULL;
            delete d;
        }

        // Case-2: if there is one child
        else if (d->left == NULL)
        { // right child exists
            if (d->parent)
            {

                if (d->parent->key < d->key)
                    d->parent->right = d->right;
                else
                    d->parent->left = d->right;

                d = NULL;
                delete d;
            }
        }
        else if (d->right == NULL)
        { // left child exists
            if (d->parent)
            {
                if (d->parent->key < d->key)
                    d->parent->right = d->left;
                else
                    d->parent->left = d->left;

                d = NULL;
                delete d;
            }
        }
        //Case-3: there are two children
        else
        {
            Node *temp = minValueNode(d->right);
            root->key = temp->key;
            delete_node(root->right,temp->key);
        }
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->key << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

void dfs(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->key << " ";
        if (temp->right != NULL)
        {
            s.push(temp->right);
        }
        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
    }
}

void reverse_inorder(Node* root){
    if(root==NULL) return;
    reverse_inorder(root->right);
    cout<<root->key<<" ";
    reverse_inorder(root->left);
}

int main()
{
    Node *BST = new Node(50);
    BST = insert(BST,30);
    BST = insert(BST, 20);
    BST = insert(BST, 40);
    BST = insert(BST, 70);
    BST = insert(BST, 60);
    BST = insert(BST, 80);
    inorder(BST);
    return 0;
}


