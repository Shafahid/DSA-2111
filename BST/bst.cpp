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

Node *removeNode(Node *root, int val)
{
    /*
     * If the node becomes NULL, it will return NULL
     * Two possible ways which can trigger this case
     * 1. If we send the empty tree. i.e root == NULL
     * 2. If the given node is not present in the tree.
     */
    if(root == NULL)
        return NULL;
    /*
     * If root->key < val. val must be present in the right subtree
     * So, call the above remove function with root->right
     */
    if(root->key < val)
        root->right = removeNode(root->right,val);
    /*
     * if root->key > val. val must be present in the left subtree
     * So, call the above function with root->left
     */
    else if(root->key > val)
        root->left = removeNode(root->left,val);
    /*
     * This part will be executed only if the root->key == val
     * The actual removal starts from here
     */
    else
    {
        /*
         * Case 1: Leaf node. Both left and right reference is NULL
         * replace the node with NULL by returning NULL to the calling pointer.
         * free the node
         */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /*
         * Case 2: Node has right child.
         * replace the root node with root->right and free the right node
         */
        else if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        /*
         * Case 3: Node has left child.
         * replace the node with root->left and free the left node
         */
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        /*
         * Case 4: Node has both left and right children.
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
        else
        {
            int rightMin = minValueNode(root->right)->key;
            root->key = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }

    //return the actual root's address
    return root;
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
     cout<<endl;
     removeNode(BST,50);
     cout<<endl;
     inorder(BST);

    return 0;
}

