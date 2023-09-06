#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H


class customer
{
    private:
        BST* bst;
        int account;
    public:
        customer(BST* &bst)
        {
            bst = bst;
            cout<<"Enter account number : ";
            cin>>account;
        }
        BST* function();
        int deposit(int);// will return the current balance
        int withdraw(int);// will return the current balance
        int checkBal();
};


BST* customer :: function()
{
    while(true)
    {
        cout<<"choose the following "<<endl;
        cout<<"1. Check balance"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. exit"<<endl;
        int condition;
        cin>>condition;
        if(condition == 1)
        {
            checkBal();
        }
        else if(condition == 2)
        {
            int am;
            cout<<"Enter amount : ";
            cin>>am;
            cout<<"current balance is "<<deposit(am)<<endl;
        }
        else if(condition == 3)
        {
            int am;
            cout<<"Enter amount : ";
            cin>>am;
            cout<<"Current balance is "<<withdraw(am)<<endl;
        }
        else
        {
            return bst;
        }
    }
}



int customer :: checkBal()
{
    return (getBST_node(bst,account)->v).amount;
}


int customer :: deposit(int am)
{
    BST* Account_node = getBST_node(bst,account);
    if(Account_node)
    {
        (Account_node->v).account += am;
    }
    
    return (Account_node->v).amount;
}

int customer :: withdraw(int am)
{
    BST* Account_node = getBST_node(bst,account);
    if(Account_node)
    {
        (Account_node->v).account -= am;
    }
    
    return (Account_node->v).amount;
}







#endif