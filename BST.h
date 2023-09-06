#pragma once


#include <string>
using namespace std;

class Node
{
   public:
    string name,address;
    int account,amount;
    Node()
    {
        name = "";address = "";account = 0;amount = 0;
    }
    Node(string n,int acc,int am,string add)
    {
        this->name = n;
        this->account = acc;
        this->address = add;
        this->amount = am;
    }
    
    void Print()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Account : "<<account<<endl;
        cout<<"Balance : "<<amount<<endl;
        cout<<"Address : "<<address<<endl;
    }
    int getBalance()

    {
        return this->amount;
    }
    void changeAddress(string add)
    {
        this->address = add;
    }
    void addAmount(int bal)
    {
        this->amount = bal;
    }
};



class BST
{
   public:
    Node v;
    BST *right,*left;
    BST(Node n)
    {
        this->v = n;
        right = nullptr;
        left = nullptr;
    }
    
};


BST* Add(BST* ,Node ); 
BST* Delete(BST* ,int );
Node* getInfo(BST* ,Node* );
int max(int ,int );
int height(BST* );
int getBalanceIndex(BST* );
BST* rightRotate(BST* );
BST* leftRotate(BST* );
BST* getBST_node(BST* ,int);



BST* Add(BST* root,Node n)      // add an element in binary search tree
{
    BST* new_bst = new BST(n);
    if(root == nullptr)
        return new_bst;
    
    if(root->v.account > n.account)
        root->left = Add(root->left,n);
    else if(root->v.account < n.account)
        root->right = Add(root->right,n);
    else
        return root;
        
    int balance = getBalanceIndex(root);
    
    if(balance>1 and n.account < root->left->v.account)   //left left case
        return rightRotate(root);
    if(balance<-1 and n.account > root->right->v.account) // right right case
        return leftRotate(root);
    
    if(balance>1 and n.account > root->left->v.account)   //left right case
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if(balance<-1 and n.account < root->right->v.account) // right left case
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

BST* Delete(BST* root,int n)  // delete technique of binary search technique
{
    if (root->v.account == n)
        return nullptr;
    if (root->v.account > n){
        root->left = Delete(root->left,n);
    }
    else if (root->v.account < n){
        root->right = Delete(root->right,n);
    }
    else
    {
        if(root->left == nullptr){
            root = root->right;
        }
        else if(root->right == nullptr){
            root = root->left;
        }
        else
        {
            BST* succ = root->right;    // get the minimum of the right subtree
            while(succ->left)
            {
                succ = succ->left;
            }
            root->v = succ->v;
            root->right = Delete(root->right,succ->v.account);
            
        }
    }
    
    
    int balance = getBalanceIndex(root);
    if(balance>1 and getBalanceIndex(root->left)>=0)        // LL case
        return rightRotate(root);
    if(balance >1 and getBalanceIndex(root->left) < 0)      // LR case
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance <-1 and getBalanceIndex(root->right) <= 0)   //RR case
        return leftRotate(root->right);
    if(balance < -1 and getBalanceIndex(root->right) > 0)   //RL case
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

Node getInfo(BST* bst,int value)  // search technique of binary search tree
{
    if(bst == nullptr)
    {
        cout<<"Account not found"<<endl;
    }
    if(bst->v.account == value)
        return bst->v;
        
    else if(bst->v.account < value)
        return getInfo(bst->right,value);
    else
        return getInfo(bst->left,value);
}

int max(int a,int b)
{
    return (a>b)? a:b;
}

int height(BST* root)
{
    if (!root)
        return -1;
    return max(height(root->left),height(root->right))+1;
}

int getBalanceIndex(BST* bst)
{
    if(bst != nullptr)
        return 0;
    return height(bst->left) - height(bst->right);
}


BST* rightRotate(BST* root)
{
    BST* L = root->left;
    BST* LR = root->left->right;
    root->left = LR;
    L->right = root;
    return L;
}

BST* leftRotate(BST* root)
{
    BST* R = root->right;
    BST* RL = root->right->left;
    root->right = RL;
    R->left = root;
    return R;
}


BST* getBST_node(BST* root,int acc)
{
    if(!root){
        cout<<"Account number not found"<<endl;
        return nullptr;
    }
    while(root and root->v.account != acc)
    {
        if (root->v.account < acc)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}










